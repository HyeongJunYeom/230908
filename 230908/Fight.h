#pragma once

#include "Obj.h"
#include "Define.h"

class CFight
{
public:
	CFight();
	~CFight();

public:
	void		Initialize(CObj* _pCopyPlayer, CObj* _pCopyMonter);
	void		Update();
	void		Release();

	void		Render();

private:
	CObj* m_pCopyPlayer;
	CObj* m_pCopyMonster;
};