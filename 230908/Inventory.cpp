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

	cout << "=====인벤토리=====" << endl << endl;

	for (int i = 0; i < vecInven.size(); ++i)
	{
		cout << i + 1 << "번 아이템" << endl;

		if (iter != vecInven.end())
		{
			vecInven[i]->Render();
		}
		else
		{
			cout << "비어있음" << endl << endl;
		}
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

bool CInventory::Delete_Item(int _iIdx)
{
	vector<CObj*>::iterator iter = vecInven.begin();

	if (_iIdx < 0 && vecInven.size() <= _iIdx)
	{
		cout << "인벤토리 범위를 벗어난 입력입니다." << endl;
	}
	
	iter += _iIdx - 1;

	if (*iter)
	{
		delete (*iter);
		(*iter) = nullptr;
		iter = vecInven.erase(iter);
		cout << "아이템 삭제 성공" << endl;
		return true;
	}

	else
	{
		cout << "아이템 삭제 실패" << endl;
		return false;
	}

}
