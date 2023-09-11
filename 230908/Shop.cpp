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
		cout << "선택: ";
		cin >> iChoice;
		iCount = 0;

		switch (iChoice)
		{
		case 1:
			for (iter = vecWeapon.begin(); iter != vecWeapon.end(); ++iter)
			{
				cout << ++iCount << "번 무기" << endl << endl;
				(*iter)->Render();
				cout << endl;
			}

			cout << endl;
			cout << "1. 아이템 구매" << endl;
			cout << "2. 돌아가기" << endl;
			cout << "선택: ";

			cin >> iChoice;
			cout << endl;

			if (1 == iChoice)
			{
				cout << "구매하고 싶은 아이템 번호: ";
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
							cout << "아이템" << BuyItem->Get_Name() << "을 구매하였습니다." << endl << endl;
							cout << "현재 소지금: " << m_pCopyPlayer->Get_Gold() << endl << endl;
							break;
						}
						else
						{
							cout << "가방에 공간이 부족합니다." << endl;
						}						
					}
					else
					{
						cout << "금화가 부족합니다." << endl;
					}
					cout << "아이템 구매에 실패하였습니다." << endl << endl;
					Safe_Delete(BuyItem);
				}
				else
				{
					cout << "보기에 없는 선택입니다. 다시 입력하세요." << endl << endl;
					break;
				}
			}
			break;

		case 2:
			for (iter = vecArmor.begin(); iter != vecArmor.end(); ++iter)
			{
				cout << ++iCount << "번 방어구" << endl << endl;
				(*iter)->Render();
				cout << endl;
			}

			cout << endl;
			cout << "1. 아이템 구매" << endl;
			cout << "2. 돌아가기" << endl;
			cout << "선택: ";

			cin >> iChoice;

			if (1 == iChoice)
			{
				cout << "구매하고 싶은 아이템 번호: ";
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
							cout << "아이템" << BuyItem->Get_Name() << "을 구매하였습니다." << endl << endl;
							cout << "현재 소지금: " << m_pCopyPlayer->Get_Gold() << endl << endl;
							break;
						}
						else
						{
							cout << "가방에 공간이 부족합니다." << endl;
						}
					}
					else
					{
						cout << "금화가 부족합니다." << endl;
					}
					cout << "아이템 구매에 실패하였습니다." << endl << endl;
				}
				else
				{
					cout << "보기에 없는 선택입니다. 다시 입력하세요." << endl << endl;
					break;
				}
			}
			break;

		case 3:
			cout << "===== 아이템 판매 =====" << endl << endl;

			dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Inventory()->Render();

			cout << endl;
			cout << "1. 아이템 판매" << endl;
			cout << "2. 돌아가기" << endl;
			cout << "선택: ";

			cin >> iChoice;

			if (1 == iChoice)
			{
				cout << "판매하고 싶은 아이템 번호: ";
				cin >> iChoice;
				if (iChoice >= 0 && dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Inventory()->Get_Inven().size() > iChoice)
				{
					CObj* SellItem = dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Inventory()->Get_Inven()[iChoice - 1];

					dynamic_cast<CPlayer*>(m_pCopyPlayer)->Set_AddGold(SellItem->Get_Gold() + m_pCopyPlayer->Get_Gold());
					if (dynamic_cast<CPlayer*>(m_pCopyPlayer)->Get_Inventory()->Delete_Item(iChoice - 1))
					{
						cout << "아이템 " << SellItem->Get_Name() << "을 판매하였습니다." << endl << endl;
						cout << "골드 " << SellItem->Get_Gold() << "를 획득하였습니다." << endl << endl;
					}
					else
					{
						cout << "아이템 판매에 실패하였습니다." << endl << endl;
					}
				}
				else
				{
					cout << "인벤토리 범위를 벗어난 입력입니다." << endl;
				}
			}
			break;

		case 4:
			cout << "마을로 돌아갑니다." << endl << endl;
			return;

		default:
			cout << "보기에 없는 입력입니다. 다시 입력하세요." << endl << endl;
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
	cout << "===== 상점 메뉴 =====" << endl << endl;

	cout << "1. 무기 상점" << endl;
	cout << "2. 방어구 상점" << endl;
	cout << "3. 아이템 판매" << endl;
	cout << "4. 마을로 돌아간다." << endl;
}


int CShop::m_iMerchantMoney = 500;