#include "pch.h"
#include "Town.h"
#include "Field.h"
#include "Shop.h"
#include "Inn.h"

CTown::CTown()
	: m_pSpace(nullptr)
{
}

CTown::~CTown()
{
	Release();
}

void CTown::Initialize()
{
}

void CTown::Update()
{
	int iChoice(0);
	while (true)
	{
		system("cls");
		
		Render();
		cout << "����: ";
		cin >> iChoice;
		cout << endl;

		switch (iChoice)
		{
		case 1:
			m_pSpace = new CField;

			break;

		case 2:
			m_pSpace = new CShop;
			break;

		case 3:
			m_pSpace = new CInn;
			break;

		case 4:
			m_pCopyPlayer->Render();
			system("pause");

			continue;

		case 5:
			dynamic_cast<CPlayer*>(m_pCopyPlayer)->Inventory();
			system("pause");

			continue;

		case 6:
			if (Save_Game())
			{
				Release();

				return;
			}
			else
				continue;

		default:
			cout << "���⿡ ���� �Է��Դϴ�. �ٽ� �Է��ϼ���. " << endl << endl;
			system("pause");

			continue;
		}

		m_pSpace->Initialize();
		m_pSpace->Set_Player(m_pCopyPlayer);
		m_pSpace->Update();
		m_pSpace->Release();

		Safe_Delete(m_pSpace);

		system("pause");
	}
}

void CTown::Release()
{
	Safe_Delete(m_pSpace);
}

void CTown::Render() const
{
	cout << "===== ���� �޴� =====" << endl << endl;

	cout << "1. �ʵ�� ������." << endl;
	cout << "2. ������ �湮�Ѵ�." << endl;
	cout << "3. ������ �湮�Ѵ�." << endl;
	cout << "4. �÷��̾� ���� ���" << endl;
	cout << "5. �κ��丮 ���" << endl;
	cout << "6. ���θ޴��� ���ư���." << endl;
}

bool CTown::Save_Game() const
{
	FILE* fSave = nullptr;
	errno_t err =fopen_s(&fSave, "../data/save.dat", "wb");

	if (0 == err)
	{
		cout << "���� ���� ����!" << endl << endl;

		int iLen = dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Name().Get_Len();
		char* pString = new char[iLen + 1];
		strcpy_s(pString, iLen + 1,dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Name().Get_String());
		fwrite(&(iLen), sizeof(int), 1, fSave);
		fwrite(pString, sizeof(char), strlen(pString) + 1, fSave);
		delete[] pString;

		iLen = dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_JobString().Get_Len();
		pString = new char[iLen + 1];
		strcpy_s(pString, iLen + 1, dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_JobString().Get_String());
		fwrite(&(iLen), sizeof(int), 1, fSave);
		fwrite(pString, sizeof(char), strlen(pString) + 1, fSave);
		delete[] pString;

		dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_SaveData();

		fwrite(dynamic_cast<CPlayer*>(m_pCopyPlayer), sizeof(CPlayer), 1, fSave);

		cout << "����Ϸ�!" << endl << endl;

		cout << "���� ȭ������ ���ư��ϴ�." << endl << endl;

		fclose(fSave);
		system("pause");
		return true;
	}
	else
	{
		cout << "���� ���� ����!" << endl << endl;

		cout << "������ ���ư��ϴ�." << endl << endl;

		fclose(fSave);
		system("pause");
		return false;
	}
}
