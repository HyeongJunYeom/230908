#pragma once

#include "Item.h"
#include <vector>

class CInventory
{
public:
	CInventory();
	~CInventory();

public:
	void		Release();

public:
	void		Render() const;

	bool		Add_Item(CObj* _pItem);
	bool		Delete_Item(int _iIdx);

public:
	vector<CObj*>&		Get_Inven() { return vecInven; }

private:
	vector<CObj*>		vecInven;
};
