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
		cout << "선택: ";
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
			dynamic_cast<CPlayer*>(m_pCopyPlayer)->SaveData();
			system("pause");
			return;

		default:
			cout << "보기에 없는 입력입니다. 다시 입력하세요. " << endl << endl;
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
	cout << "===== 마을 메뉴 =====" << endl << endl;

	cout << "1. 필드로 나간다." << endl;
	cout << "2. 상점에 방문한다." << endl;
	cout << "3. 여관에 방문한다." << endl;
	cout << "4. 플레이어 상태 출력" << endl;
	cout << "5. 인벤토리 출력" << endl;
	cout << "6. 메인메뉴로 돌아간다." << endl;
}