#pragma once

#include "Item.h"

class CArmor : public CItem
{
public:
	CArmor(int _iType);
	~CArmor();

public:
	void		Render() const override;
	void		Initialize() override;
};

