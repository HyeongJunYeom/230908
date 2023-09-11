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
	int iType(0);

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

			cout << endl;
			cout << "1. ������ ����" << endl;
			cout << "2. ���ư���" << endl;
			cout << "����: ";

			cin >> iChoice;
			cout << endl;

			if (1 == iChoice)
			{
				cout << "�����ϰ� ���� ������ ��ȣ: ";
				cin >> iChoice;

				if (iChoice <= iCount && 0 < iChoice)
				{
					iType = dynamic_cast<CWeapon*>(vecWeapon[iChoice - 1])->Get_Type();
					CObj* BuyItem = new CWeapon(iType);
					dynamic_cast<CWeapon*>(BuyItem)->Initialize();

					if (m_pCopyPlayer->Get_Gold() >= BuyItem->Get_Gold())
					{
						dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_MinGold(BuyItem->Get_Gold());
						if (dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Inventory()->Add_Item(BuyItem))
						{
							cout << "������" << BuyItem->Get_Name() << "�� �����Ͽ����ϴ�." << endl << endl;
							cout << "���� ������: " << m_pCopyPlayer->Get_Gold() << endl << endl;
							break;
						}
						else
						{
							cout << "���濡 ������ �����մϴ�." << endl;
						}						
					}
					else
					{
						cout << "��ȭ�� �����մϴ�." << endl;
					}
					cout << "������ ���ſ� �����Ͽ����ϴ�." << endl << endl;
					Safe_Delete(BuyItem);
				}
				else
				{
					cout << "���⿡ ���� �����Դϴ�. �ٽ� �Է��ϼ���." << endl << endl;
					break;
				}
			}
			break;

		case 2:
			for (iter = vecArmor.begin(); iter != vecArmor.end(); ++iter)
			{
				cout << ++iCount << "�� ��" << endl << endl;
				(*iter)->Render();
				cout << endl;
			}

			cout << endl;
			cout << "1. ������ ����" << endl;
			cout << "2. ���ư���" << endl;
			cout << "����: ";

			cin >> iChoice;

			if (1 == iChoice)
			{
				cout << "�����ϰ� ���� ������ ��ȣ: ";
				cin >> iChoice;

				if (iChoice <= iCount && 0 < iChoice)
				{
					iType = dynamic_cast<CArmor*>(vecArmor[iChoice - 1])->Get_Type();
					CObj* BuyItem = new CArmor(iType);
					dynamic_cast<CArmor*>(BuyItem)->Initialize();

					if (m_pCopyPlayer->Get_Gold() >= BuyItem->Get_Gold())
					{
						dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_MinGold(BuyItem->Get_Gold());
						if (dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Inventory()->Add_Item(BuyItem))
						{
							cout << "������" << BuyItem->Get_Name() << "�� �����Ͽ����ϴ�." << endl << endl;
							cout << "���� ������: " << m_pCopyPlayer->Get_Gold() << endl << endl;
							break;
						}
						else
						{
							cout << "���濡 ������ �����մϴ�." << endl;
						}
					}
					else
					{
						cout << "��ȭ�� �����մϴ�." << endl;
					}
					cout << "������ ���ſ� �����Ͽ����ϴ�." << endl << endl;
				}
				else
				{
					cout << "���⿡ ���� �����Դϴ�. �ٽ� �Է��ϼ���." << endl << endl;
					break;
				}
			}
			break;

		case 3:
			cout << "===== ������ �Ǹ� =====" << endl << endl;

			dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Inventory()->Render();

			cout << endl;
			cout << "1. ������ �Ǹ�" << endl;
			cout << "2. ���ư���" << endl;
			cout << "����: ";

			cin >> iChoice;

			if (1 == iChoice)
			{
				cout << "�Ǹ��ϰ� ���� ������ ��ȣ: ";
				cin >> iChoice;
				if (iChoice >= 0 && dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Inventory()->Get_Inven().size() > iChoice)
				{
					CObj* SellItem = dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Inventory()->Get_Inven()[iChoice - 1];

					dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_AddGold(SellItem->Get_Gold() + m_pCopyPlayer->Get_Gold());
					if (dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Inventory()->Delete_Item(iChoice - 1))
					{
						cout << "������ " << SellItem->Get_Name() << "�� �Ǹ��Ͽ����ϴ�." << endl << endl;
						cout << "��� " << SellItem->Get_Gold() << "�� ȹ���Ͽ����ϴ�." << endl << endl;
					}
					else
					{
						cout << "������ �Ǹſ� �����Ͽ����ϴ�." << endl << endl;
					}
				}
				else
				{
					cout << "�κ��丮 ������ ��� �Է��Դϴ�." << endl;
				}
			}
			break;

		case 4:
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
	cout << "3. ������ �Ǹ�" << endl;
	cout << "4. ������ ���ư���." << endl;
}


int CShop::m_iMerchantMoney = 500;