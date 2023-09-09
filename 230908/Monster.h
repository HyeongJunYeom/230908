#pragma once

#include "Creature.h"

class CMonster : public CCreature
{
public:
	CMonster();
	~CMonster() override;

public:
	void		Render() const override;
};

