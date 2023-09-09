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
		cout << "����: ";
		cin >> iChoice;
		cout << endl;

		switch (iChoice)
		{
		case 1:
			if (dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Gold() < 50)
			{
				cout << "�������� �����մϴ�.	" << endl;
				cout << "���� ������: " << dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Gold() << " G" << endl << endl;
				system("pause");

				continue;
			}
			else
			{
				cout << "�޽��� ���մϴ�...." << endl << endl;
				dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_MinGold(50);

				cout << "ü���� 50 ȸ���߽��ϴ�." << endl << endl;
				dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_AddHp(50);

				system("pause");
			}
			break;

		case 2:
			cout << "������ ���ư��ϴ�..." << endl << endl;

			system("pause");

			return;

		default:
			cout << "���⿡ ���� �Է��Դϴ�. �ٽ� �Է��ϼ���. " << endl << endl;
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
	cout << "===== ���� �޴� =====" << endl << endl;

	cout << "1. �޽��� ���Ѵ�. (50 G)" << endl;
	cout << "2. ������ ���ư���." << endl;
}
