#include "pch.h"
#include "Inn.h"

CInn::CInn()
{
}

CInn::~CInn()
{
	Release();
}

void CInn::Initialize()
{
}

void CInn::Update()
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
			if (dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Gold() < 50)
			{
				cout << "소지금이 부족합니다.	" << endl;
				cout << "현재 소지금: " << dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Gold() << " G" << endl << endl;
				system("pause");

				continue;
			}
			else
			{
				cout << "휴식을 취합니다...." << endl << endl;
				dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_MinGold(50);

				cout << "체력을 50 회복했습니다." << endl << endl;
				dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_AddHp(50);

				system("pause");
			}
			break;

		case 2:
			cout << "마을로 돌아갑니다..." << endl << endl;

			system("pause");

			return;

		default:
			cout << "보기에 없는 입력입니다. 다시 입력하세요. " << endl << endl;
			system("pause");

			continue;
		}
	}
}

void CInn::Release()
{
	m_pCopyPlayer = nullptr;
}

void CInn::Render() const
{
	cout << "===== 여관 메뉴 =====" << endl << endl;

	cout << "1. 휴식을 취한다. (50 G)" << endl;
	cout << "2. 마을로 돌아간다." << endl;
}
