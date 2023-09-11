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
	vector<CObj*>::const_iterator iter = vecInven.begin();

	cout << "=====�κ��丮=====" << endl << endl;

	for (int i = 0; i < vecInven.size(); ++i)
	{
		cout << i + 1 << "�� ������" << endl;

		if (iter != vecInven.end())
		{
			vecInven[i]->Render();
		}
		else
		{
			cout << "�������" << endl << endl;
		}
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

bool CInventory::Delete_Item(int _iIdx)
{
	vector<CObj*>::iterator iter = vecInven.begin();

	if (_iIdx < 0 && vecInven.size() <= _iIdx)
	{
		cout << "�κ��丮 ������ ��� �Է��Դϴ�." << endl;
	}
	
	iter += _iIdx - 1;

	if (*iter)
	{
		delete (*iter);
		(*iter) = nullptr;
		iter = vecInven.erase(iter);
		cout << "������ ���� ����" << endl;
		return true;
	}

	else
	{
		cout << "������ ���� ����" << endl;
		return false;
	}

}
