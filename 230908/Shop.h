#pragma once

#include "Space.h"
#include <vector>

class CShop : public CSpace
{
public:
	CShop();
	~CShop() override;

public:
	void		Initialize() override;
	void		Update() override;
	void		Release() override;
	void		Render() const override;

	int			Get_MerchantMoney() const { return m_iMerchantMoney; }

	static int m_iMerchantMoney;

private:
	vector<CObj*>		vecWeapon;
	vector<CObj*>		vecArmor;
};


