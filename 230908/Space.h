#pragma once

#include "Player.h"
#include "Define.h"

class CSpace
{
public:
	CSpace();
	virtual ~CSpace();

public:
	virtual void Initialize() PURE;
	virtual void Update() PURE;
	virtual void Release();
	virtual void Render() const PURE;
	
	void		Set_Player(CObj* _pPlayer);

protected:
	CObj*		m_pCopyPlayer;
};

