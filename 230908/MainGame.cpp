#include "pch.h"
#include "MainGame.h"
#include "Town.h"


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

			break;

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
		
		Safe_Delete(m_pTown);
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
