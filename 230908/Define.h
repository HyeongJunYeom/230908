#pragma once

#define PURE	=0

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

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