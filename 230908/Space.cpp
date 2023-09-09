#include "pch.h"
#include "Space.h"

CSpace::CSpace()
	: m_pCopyPlayer(nullptr)
{
}

CSpace::~CSpace()
{
	Release();
}

void CSpace::Release()
{
	m_pCopyPlayer = nullptr;
}


void CSpace::Set_Player(CObj* _pPlayer)
{
	m_pCopyPlayer = _pPlayer;
}
