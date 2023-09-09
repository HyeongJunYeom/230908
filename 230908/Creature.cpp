#include "pch.h"
#include "Creature.h"

void CCreature::Attack(CCreature& _target)
{
	_target.Set_Hp(_target.Get_Hp() - Get_Attack());
}
