#include "pch.h"
#include "Fight.h"
#include "Player.h"
#include "Monster.h"

CFight::CFight()
	: m_pCopyPlayer(nullptr), m_pCopyMonster(nullptr)
{

}

CFight::~CFight()
{
	Release();
}

void CFight::Initialize(CObj* _pCopyPlayer, CObj* _pCopyMonter)
{
	Safe_Delete(m_pCopyPlayer);
	Safe_Delete(m_pCopyMonster);

	m_pCopyPlayer = _pCopyPlayer;
	m_pCopyMonster = _pCopyMonter;
}

void CFight::Update()
{
	int iChoice(0);

	while (true)
	{
		system("cls");

		dynamic_cast<CPlayer*>(m_pCopyPlayer)->Render();
		dynamic_cast<CMonster*>(m_pCopyMonster)->Render();

		Render();
		cout << "����: ";
		cin >> iChoice;
		cout << endl;

		switch (iChoice)
		{
		case 1:
			cout << "�÷��̾� " << m_pCopyPlayer->Get_Name() 
				<< "�� ����!" << endl;
			system("pause");

			dynamic_cast<CPlayer*>(m_pCopyPlayer)->Attack((*dynamic_cast<CMonster*>(m_pCopyMonster)));

			cout << "���� " << m_pCopyMonster->Get_Name() 
				<< "���� " << m_pCopyPlayer->Get_Attack() 
				<< "�� �������� �־���!" << endl << endl;
			system("pause");

			if (m_pCopyMonster->Get_Hp() <= 0)
			{
				cout << "�¸�" << endl;
				dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_AddExp(dynamic_cast<CMonster*>(m_pCopyMonster)->Get_Exp());
				dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_AddGold(dynamic_cast<CMonster*>(m_pCopyMonster)->Get_Gold());

				cout << "����ġ " << dynamic_cast<CMonster*>(m_pCopyMonster)->Get_Exp() << "ȹ��! " << endl;
				cout << "��ȭ " << dynamic_cast<CMonster*>(m_pCopyMonster)->Get_Gold() << "ȹ��! " << endl;
				return;
			}

			cout << "���� " << m_pCopyMonster->Get_Name()
				<< "�� ����!" << endl;
			system("pause");
			
			dynamic_cast<CMonster*>(m_pCopyMonster)->Attack((*dynamic_cast<CPlayer*>(m_pCopyPlayer)));

			cout << "�÷��̾� " << m_pCopyPlayer->Get_Name()
				<< "���� " << m_pCopyMonster->Get_Attack()
				<< "�� �������� �־���!" << endl << endl;
			system("pause");

			if (m_pCopyPlayer->Get_Hp() <= 0)
			{
				cout << "�й�" << endl;
				dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_MinExp(5);
				dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_AddHp(5);
				return;
			}
			break;

		case 2:
			cout << "����Ĩ�ϴ�." << endl;

			cout << "������ ���ư��ϴ�." << endl << endl;

			Release();
			return;

		default:
			cout << "���⿡ ���� �Է��Դϴ�. �ٽ� �Է��ϼ���. " << endl << endl;
			system("pause");

			continue;
		}
	}
}

void CFight::Release()
{
	if (m_pCopyPlayer)
		m_pCopyPlayer = nullptr;
	if (m_pCopyMonster)
		m_pCopyMonster = nullptr;
}

void CFight::Render()
{
	cout << "===== ���� �޴� =====" << endl << endl;

	cout << "1. ����" << endl;
	cout << "2. ����" << endl;
}
