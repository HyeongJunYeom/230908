#include "pch.h"
#include "MainGame.h"
#include "Town.h"
#include "String.h"
#include "Weapon.h"
#include "Armor.h"


CMainGame::CMainGame()
	: m_pPlayer(nullptr), m_pTown(nullptr)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	if(!m_pPlayer)
		m_pPlayer = new CPlayer;
	if (!m_pTown)
		m_pTown = new CTown;
}

void CMainGame::Update()
{
	int iChoice(0);
	while (true)
	{
		system("cls");

		Render();

		cout << "����: ";
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			dynamic_cast<CPlayer*>(m_pPlayer)->Initialize();
			
			break;

		case 2:
			if (Load_Game())
			{
				break;
			}
			else
			{
				continue;
			}
		case 3:
			cout << "���α׷��� �����մϴ�." << endl << endl;
			Release();

			system("pause");
			return;

		default:
			cout << "���⿡ ���� �Է��Դϴ�. �ٽ� �Է��ϼ���. " << endl << endl;
			system("pause");

			continue;
		}

		m_pTown->Initialize();
		m_pTown->Set_Player(m_pPlayer);
		m_pTown->Update();
	}
}

void CMainGame::Release()
{
	Safe_Delete(m_pPlayer);
	Safe_Delete(m_pTown);
}

void CMainGame::Render()
{/*
	Sleep(500);
	system("cls");
	cout << "��...";
	Sleep(500);
	system("cls");
	cout << "����...";
	Sleep(500);
	system("cls");
	cout << "�����...";
	Sleep(500);
	system("cls");
	cout << "�������...";
	Sleep(500);
	system("cls");
	cout << "������� ��...";
	Sleep(500);
	system("cls");
	cout << "������� �¶�...";
	Sleep(500);
	system("cls");
	cout << "������� �¶���..." << endl << endl;*/

	cout << "===== ���� �޴� =====" << endl << endl;

	cout << "1. �� ����" << endl;
	cout << "2. �ҷ�����" << endl;
	cout << "3. ���� ����" << endl;
}

bool CMainGame::Load_Game()
{
	FILE* fLoad = nullptr;
	errno_t err = fopen_s(&fLoad, "../data/save.dat", "rb");

	if (0 == err)
	{
		cout << "���� ���� ����!" << endl << endl;
		
		Safe_Delete(m_pPlayer);

		CPlayer* LoadPlayer = new CPlayer;

		int iLen = 0;
		char szBuf[100] = "";

		fread(&iLen, sizeof(int), 1, fLoad);
		fread(szBuf, sizeof(char), iLen + 1, fLoad);

		String Name(szBuf);

		fread(&iLen, sizeof(int), 1, fLoad);
		fread(szBuf, sizeof(char), iLen + 1, fLoad);

		String JobString(szBuf);

		fread(LoadPlayer, sizeof(CPlayer), 1, fLoad);
		LoadPlayer->Set_LoadData(Name, JobString);

		int iItemCount(0);
		fread(&iItemCount, sizeof(int), 1, fLoad);
		
		CObj* loadItem = nullptr;

		int iType(0);
		int iDura(0);

		

		for (int iIdx = 0; iIdx < iItemCount; ++iIdx)
		{
			fread(&iType, sizeof(int), 1, fLoad);

			if (NORMAL_WEAPON <= iType && WEAPON_END > iType)
			{
				loadItem = new CWeapon(iType);
				dynamic_cast<CItem*>(loadItem)->Initialize();
			}
			else if (NORMAL_ARMOR <= iType && ARMOR_END > iType)
			{
				loadItem = new CArmor(iType);
				dynamic_cast<CItem*>(loadItem)->Initialize();
			}
			fread(&iDura, sizeof(int), 1, fLoad);
			dynamic_cast<CItem*>(loadItem)->Set_Dura(iDura);
			LoadPlayer->Get_Inventory()->Add_Item(loadItem);
		}
		
		bool bEquipWeapon(false);
		bool bEquipArmor(false);

		fread(&bEquipWeapon, sizeof(bool), 1, fLoad);
		fread(&bEquipArmor, sizeof(bool), 1, fLoad);

		if (bEquipWeapon)
		{
			fread(&iType, sizeof(int), 1, fLoad);
			loadItem = new CWeapon(iType);
			dynamic_cast<CItem*>(loadItem)->Initialize();
			fread(&iDura, sizeof(int), 1, fLoad);
			dynamic_cast<CItem*>(loadItem)->Set_Dura(iDura);
			LoadPlayer->Equip_Wepon(loadItem);
		}

		if (bEquipArmor)
		{
			fread(&iType, sizeof(int), 1, fLoad);
			loadItem = new CArmor(iType);
			dynamic_cast<CItem*>(loadItem)->Initialize();
			fread(&iDura, sizeof(int), 1, fLoad);
			dynamic_cast<CItem*>(loadItem)->Set_Dura(iDura);
			LoadPlayer->Equip_Wepon(loadItem);
		}

		m_pPlayer = LoadPlayer;

		cout << "�ҷ����� �Ϸ�!" << endl << endl;

		cout << "������ �����մϴ�." << endl << endl;
		fclose(fLoad);
		system("pause");
		return true;
	}
	else
	{
		cout << "���� ���� ����!" << endl << endl;

		cout << "���θ޴��� ���ư��ϴ�." << endl << endl;

		fclose(fLoad);
		system("pause");
		return false;
	}
}
