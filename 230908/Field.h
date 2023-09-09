#pragma once

#include "Space.h"
#include "NormalMonster.h"
#include "RareMonster.h"
#include "EpicMonster.h"
#include "Fight.h"

class CField : public CSpace
{
public:
	CField();
	~CField() override;

public:
	void Initialize() override;
	void Update() override;
	void Release() override;
	void Render() const override;

public:
	CObj* m_pMonster;
	CFight* m_pFight;
};