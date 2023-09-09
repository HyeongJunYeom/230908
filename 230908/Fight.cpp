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
		cout << "선택: ";
		cin >> iChoice;
		cout << endl;

		switch (iChoice)
		{
		case 1:
			cout << "플레이어 " << m_pCopyPlayer->Get_Name() 
				<< "의 공격!" << endl;
			system("pause");

			dynamic_cast<CPlayer*>(m_pCopyPlayer)->Attack((*dynamic_cast<CMonster*>(m_pCopyMonster)));

			cout << "몬스터 " << m_pCopyMonster->Get_Name() 
				<< "에게 " << m_pCopyPlayer->Get_Attack() 
				<< "의 데미지를 주었다!" << endl << endl;
			system("pause");

			if (m_pCopyMonster->Get_Hp() <= 0)
			{
				cout << "승리" << endl;
				dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_AddExp(dynamic_cast<CMonster*>(m_pCopyMonster)->Get_Exp());
				dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_AddGold(dynamic_cast<CMonster*>(m_pCopyMonster)->Get_Gold());

				cout << "경험치 " << dynamic_cast<CMonster*>(m_pCopyMonster)->Get_Exp() << "획득! " << endl;
				cout << "금화 " << dynamic_cast<CMonster*>(m_pCopyMonster)->Get_Gold() << "획득! " << endl;
				return;
			}

			cout << "몬스터 " << m_pCopyMonster->Get_Name()
				<< "의 공격!" << endl;
			system("pause");
			
			dynamic_cast<CMonster*>(m_pCopyMonster)->Attack((*dynamic_cast<CPlayer*>(m_pCopyPlayer)));

			cout << "플레이어 " << m_pCopyPlayer->Get_Name()
				<< "에게 " << m_pCopyMonster->Get_Attack()
				<< "의 데미지를 주었다!" << endl << endl;
			system("pause");

			if (m_pCopyPlayer->Get_Hp() <= 0)
			{
				cout << "패배" << endl;
				dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_MinExp(5);
				dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_AddHp(5);
				return;
			}
			break;

		case 2:
			cout << "도망칩니다." << endl;

			cout << "마을로 돌아갑니다." << endl << endl;

			Release();
			return;

		default:
			cout << "보기에 없는 입력입니다. 다시 입력하세요. " << endl << endl;
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
	cout << "===== 전투 메뉴 =====" << endl << endl;

	cout << "1. 공격" << endl;
	cout << "2. 도망" << endl;
}
