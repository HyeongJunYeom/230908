#include "pch.h"
#include "Field.h"

CField::CField()
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
			m_pMonster = new CRareMonster;
			dynamic_cast<CRareMonster*>(m_pMonster)->Initiallize();
			break;

		case 3:
			m_pMonster = new CEpicMonster;
			dynamic_cast<CEpicMonster*>(m_pMonster)->Initiallize();
			break;

		case 4:
			m_pCopyPlayer->Render();
			system("pause");

			continue;

		case 5:
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
	cout << "2. �߱� ����." << endl;
	cout << "3. ��� ����." << endl;
	cout << "4. �÷��̾� ���� ���" << endl;
	cout << "5. ������ ���ư���." << endl;
}
