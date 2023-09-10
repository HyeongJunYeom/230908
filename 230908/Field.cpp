#include "pch.h"
#include "Field.h"

CField::CField()
	: m_pFight(nullptr), m_pMonster(nullptr)
{
}

CField::~CField()
{
	Release();
}

void CField::Initialize()
{
}

void CField::Update()
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
			m_pMonster = new CNormalMonster;
			dynamic_cast<CNormalMonster*>(m_pMonster)->Initiallize();

			break;

		case 2:
			if (2 > dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Level())
			{
				cout << "������ �����մϴ�..." << endl;
				cout << "���� ����: " << dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Level() << endl << endl;
				system("pause");

				continue;
			}
			m_pMonster = new CRareMonster;
			dynamic_cast<CRareMonster*>(m_pMonster)->Initiallize();
			break;

		case 3:
			if (3 > dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Level())
			{
				cout << "������ �����մϴ�..." << endl;
				cout << "���� ����: " << dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Level() << endl << endl;
				system("pause");

				continue;
			}
			m_pMonster = new CEpicMonster;
			dynamic_cast<CEpicMonster*>(m_pMonster)->Initiallize();
			break;

		case 4:
			if (4 > dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Level())
			{
				cout << "������ �����մϴ�..." << endl;
				cout << "���� ����: " << dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Level() << endl << endl;
				system("pause");

				continue;
			}
			m_pMonster = new CLegendMonster;
			dynamic_cast<CLegendMonster*>(m_pMonster)->Initiallize();
			break;

		case 5:
			m_pCopyPlayer->Render();
			system("pause");

			continue;

		case 6:
			cout << "������ ���ư��ϴ�..." << endl << endl;
			Safe_Delete(m_pFight);
			Safe_Delete(m_pMonster);
			system("pause");
			return;

		default:
			cout << "���⿡ ���� �Է��Դϴ�. �ٽ� �Է��ϼ���. " << endl << endl;
			system("pause");
			continue;
		}

		m_pFight = new CFight;
		m_pFight->Initialize(m_pCopyPlayer, m_pMonster);
		m_pFight->Update();
		m_pFight->Release();

		Safe_Delete(m_pFight);
		Safe_Delete(m_pMonster);
		system("pause");
	}
}

void CField::Release()
{
	Safe_Delete(m_pFight);
	Safe_Delete(m_pMonster);
}

void CField::Render() const
{
	cout << "===== �ʵ� �޴� =====" << endl << endl;

	cout << "1. �ʱ� ����" << endl;
	cout << "2. �߱� ���� (���� 2�̻�)" << endl;
	cout << "3. ��� ���� (���� 3�̻�)" << endl;
	cout << "4. ���� ���� (���� 4�̻�)" << endl;
	cout << "5. �÷��̾� ���� ���" << endl;
	cout << "6. ������ ���ư���." << endl;
}
