#pragma once

#define PURE	=0

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

enum IT_WEAPON
{
	NORMAL_WEAPON = 2000, MAGIC_WEAPON, RARE_WEAPON, EPIC_WEAPON, WEAPON_END
};

enum IT_ARMOR
{
	NORMAL_ARMOR = 1000, MAGIC_AMROR, RARE_ARMOR, EPIC_ARMOR, ARMOR_END
};


template<typename T>
void		Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}

template<typename T>
void		Sefe_Delete_Arr(T& p)
{
	if (p)
	{
		delete[] p;
		p = nullptr;
	}
}

enum {
	WARRIOR = 1, MAGE, THIEF
};