#pragma once

#include "Player.h"
#include "Define.h"
#include "Space.h"
#include "windows.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update();
	void		Release();

public:
	void		Render();

private:
	CObj* m_pPlayer;
	CSpace* m_pTown;
};

