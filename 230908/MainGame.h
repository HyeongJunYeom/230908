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

public:
	bool		Load_Game();

private:
	CObj* m_pPlayer;
	CSpace* m_pTown;
};

