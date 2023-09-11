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

		cout << "선택: ";
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
			cout << "프로그램을 종료합니다." << endl << endl;
			Release();

			system("pause");
			return;

		default:
			cout << "보기에 없는 입력입니다. 다시 입력하세요. " << endl << endl;
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
	cout << "간...";
	Sleep(500);
	system("cls");
	cout << "간장...";
	Sleep(500);
	system("cls");
	cout << "간장게...";
	Sleep(500);
	system("cls");
	cout << "간장게장...";
	Sleep(500);
	system("cls");
	cout << "간장게장 온...";
	Sleep(500);
	system("cls");
	cout << "간장게장 온라...";
	Sleep(500);
	system("cls");
	cout << "간장게장 온라인..." << endl << endl;*/

	cout << "===== 메인 메뉴 =====" << endl << endl;

	cout << "1. 새 게임" << endl;
	cout << "2. 불러오기" << endl;
	cout << "3. 게임 종료" << endl;
}

bool CMainGame::Load_Game()
{
	FILE* fLoad = nullptr;
	errno_t err = fopen_s(&fLoad, "../data/save.dat", "rb");

	if (0 == err)
	{
		cout << "파일 개방 성공!" << endl << endl;
		
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

		cout << "불러오기 완료!" << endl << endl;

		cout << "마을에 진입합니다." << endl << endl;
		fclose(fLoad);
		system("pause");
		return true;
	}
	else
	{
		cout << "파일 개방 실패!" << endl << endl;

		cout << "메인메뉴로 돌아갑니다." << endl << endl;

		fclose(fLoad);
		system("pause");
		return false;
	}
}
