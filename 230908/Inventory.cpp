#include "pch.h"
#include "Inventory.h"
#include "Armor.h"
#include "Weapon.h"

CInventory::CInventory()
{
	vecInven.reserve(5);

	CObj* item1 = new CArmor(NORMAL_ARMOR);
	dynamic_cast<CArmor*>(item1)->Initialize();
	CObj* item2 = new CArmor(RARE_ARMOR);
	dynamic_cast<CArmor*>(item2)->Initialize();
	CObj* item3 = new CArmor(NORMAL_WEAPON);
	dynamic_cast<CWeapon*>(item3)->Initialize();
	CObj* item4 = new CArmor(RARE_WEAPON);
	dynamic_cast<CWeapon*>(item4)->Initialize();

	vecInven.push_back(item1);
	vecInven.push_back(item2);
	vecInven.push_back(item3);
	vecInven.push_back(item4);
}

CInventory::~CInventory()
{
	Release();
}

void CInventory::Release()
{
	vector<CObj*>::iterator iter;

	for (iter = vecInven.begin(); iter != vecInven.end(); )
	{
		if (*iter)
		{
			delete (*iter);
			(*iter) = nullptr;
			iter = vecInven.erase(iter);
		}
		else
		{
			++iter;
		}
	}
}

void CInventory::Render() const
{
	cout << "=====인벤토리=====" << endl << endl;

	for (int i = 0; i < vecInven.size(); ++i)
	{
		cout << i + 1 << "번 아이템" << endl;
		vecInven[i]->Render();
	}
}

bool CInventory::Add_Item(CObj* _pItem)
{
	if (5 <= vecInven.size())
	{
		cout << "인벤토리가 가득 찼습니다." << endl << endl;
		cout << "더 이상 아이템을 보관할 수 없습니다." << endl << endl;

		return false;
	}
	vecInven.push_back(_pItem);
	return true;
}

void CInventory::Delete_Item()
{
}
