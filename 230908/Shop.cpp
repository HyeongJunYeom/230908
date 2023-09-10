#include "pch.h"
#include "Shop.h"
#include "Weapon.h"
#include "Armor.h"

CShop::CShop()
{
	vecWeapon.reserve(100);
	vecArmor.reserve(100);
}

CShop::~CShop()
{
	Release();
}

void CShop::Initialize()
{
	for (int i = NORMAL_WEAPON; i < WEAPON_END; ++i)
	{
		CObj* weapon = new CWeapon(i);
		dynamic_cast<CItem*>(weapon)->Initialize();
		vecWeapon.push_back(weapon);
	}
	for (int i = NORMAL_ARMOR; i < ARMOR_END; ++i)
	{
		CObj* armor = new CArmor(i);
		dynamic_cast<CItem*>(armor)->Initialize();
		vecArmor.push_back(armor);
	}
}

void CShop::Update()
{
	int iChoice(0);
	vector<CObj*>::iterator iter;
	int iCount(0);

	while (true)
	{
		system("cls");

		Render();
		cout << "����: ";
		cin >> iChoice;
		iCount = 0;

		switch (iChoice)
		{
		case 1:
			for (iter = vecWeapon.begin(); iter != vecWeapon.end(); ++iter)
			{
				cout << ++iCount << "�� ����" << endl << endl;
				(*iter)->Render();
				cout << endl;
			}

			break;

		case 2:
			for (iter = vecArmor.begin(); iter != vecArmor.end(); ++iter)
			{
				cout << ++iCount << "�� ��" << endl << endl;
				(*iter)->Render();
				cout << endl;
			}

			break;

		case 3:
			cout << "������ ���ư��ϴ�." << endl << endl;
			return;

		default:
			cout << "���⿡ ���� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl << endl;
			system("pause");

			continue;
		}

		system("pause");
	}
}

void CShop::Release()
{
	vector<CObj*>::iterator iter;

	for (iter = vecWeapon.begin(); iter != vecWeapon.end(); )
	{
		if (*iter)
		{
			delete (*iter);
			(*iter) = nullptr;
			iter = vecWeapon.erase(iter);
		}
		else
			++iter;
	}

	for (iter = vecArmor.begin(); iter != vecArmor.end(); )
	{
		if (*iter)
		{
			delete (*iter);
			(*iter) = nullptr;
			iter = vecArmor.erase(iter);
		}
		else
			++iter;
	}
}

void CShop::Render() const
{
	cout << "===== ���� �޴� =====" << endl << endl;

	cout << "1. ���� ����" << endl;
	cout << "2. �� ����" << endl;
	cout << "3. ������ ���ư���." << endl;
}


int CShop::m_iMerchantMoney = 500;