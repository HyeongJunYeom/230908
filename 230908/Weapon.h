#pragma once

#include "Item.h"
#include "Define.h"

class CWeapon : public CItem
{
public:
	CWeapon(int _iType);
	~CWeapon();

public:
	void		Render() const override;
	void		Initialize() override;
};