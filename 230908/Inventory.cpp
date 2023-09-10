#include "pch.h"
#include "Inventory.h"
#include "Armor.h"
#include "Weapon.h"

CInventory::CInventory()
{
	vecInven.reserve(5);
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
	cout << "=====�κ��丮=====" << endl << endl;

	for (int i = 0; i < vecInven.size(); ++i)
	{
		cout << i + 1 << "�� ������" << endl;
		vecInven[i]->Render();
	}
}

bool CInventory::Add_Item(CObj* _pItem)
{
	if (5 <= vecInven.size())
	{
		cout << "�κ��丮�� ���� á���ϴ�." << endl << endl;
		cout << "�� �̻� �������� ������ �� �����ϴ�." << endl << endl;

		return false;
	}
	vecInven.push_back(_pItem);
	return true;
}

void CInventory::Delete_Item()
{
}
