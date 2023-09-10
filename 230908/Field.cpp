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
		cout << "선택: ";
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
				cout << "레벨이 부족합니다..." << endl;
				cout << "현재 레벨: " << dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Level() << endl << endl;
				system("pause");

				continue;
			}
			m_pMonster = new CRareMonster;
			dynamic_cast<CRareMonster*>(m_pMonster)->Initiallize();
			break;

		case 3:
			if (3 > dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Level())
			{
				cout << "레벨이 부족합니다..." << endl;
				cout << "현재 레벨: " << dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Level() << endl << endl;
				system("pause");

				continue;
			}
			m_pMonster = new CEpicMonster;
			dynamic_cast<CEpicMonster*>(m_pMonster)->Initiallize();
			break;

		case 4:
			if (4 > dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Level())
			{
				cout << "레벨이 부족합니다..." << endl;
				cout << "현재 레벨: " << dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Level() << endl << endl;
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
			cout << "마을로 돌아갑니다..." << endl << endl;
			Safe_Delete(m_pFight);
			Safe_Delete(m_pMonster);
			system("pause");
			return;

		default:
			cout << "보기에 없는 입력입니다. 다시 입력하세요. " << endl << endl;
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
	cout << "===== 필드 메뉴 =====" << endl << endl;

	cout << "1. 초급 던전" << endl;
	cout << "2. 중급 던전 (레벨 2이상)" << endl;
	cout << "3. 고급 던전 (레벨 3이상)" << endl;
	cout << "4. 보스 던전 (레벨 4이상)" << endl;
	cout << "5. 플레이어 상태 출력" << endl;
	cout << "6. 마을로 돌아간다." << endl;
}
