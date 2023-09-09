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

		cout << "����: ";
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			dynamic_cast<CPlayer*>(m_pPlayer)->Initialize();
			
			break;

		case 2:

			break;

		case 3:
			cout << "���α׷��� �����մϴ�." << endl << endl;
			Release();

			system("pause");
			return;

		default:
			cout << "���⿡ ���� �Է��Դϴ�. �ٽ� �Է��ϼ���. " << endl << endl;
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
	cout << "��...";
	Sleep(500);
	system("cls");
	cout << "����...";
	Sleep(500);
	system("cls");
	cout << "�����...";
	Sleep(500);
	system("cls");
	cout << "�������...";
	Sleep(500);
	system("cls");
	cout << "������� ��...";
	Sleep(500);
	system("cls");
	cout << "������� �¶�...";
	Sleep(500);
	system("cls");
	cout << "������� �¶���..." << endl << endl;*/

	cout << "===== ���� �޴� =====" << endl << endl;

	cout << "1. �� ����" << endl;
	cout << "2. �ҷ�����" << endl;
	cout << "3. ���� ����" << endl;
}
