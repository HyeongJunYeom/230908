#pragma once

#include "Obj.h"

class CCreature : public CObj
{
public:
	CCreature() {}
	CCreature(String _name, int _iHp, int _iAttack, int _iGold, int _iMaxHp, int _iExp)
		: CObj(_name, _iHp, _iAttack, _iGold), m_iMaxHp(_iMaxHp), m_iExp(_iExp) 
	{}
	~CCreature() override
	{
		Release();
	}

public:
	void		Attack(CCreature& _target);

protected:
	void	Set_MaxHp(int _iMaxHp)
	{
		if (0 > _iMaxHp)
		{
			m_iMaxHp = 0;
			return;
		}
		m_iMaxHp = _iMaxHp;
	}

	void	Set_Exp(int _iExp)
	{
		if (0 > _iExp)
		{
			m_iExp = 0;
			return;
		}

		m_iExp = _iExp;
	}

public:
	int		Get_MaxHp() const { return m_iMaxHp; }
	int		Get_Exp() const { return m_iExp; }

private:
	int		m_iMaxHp;		int m_iExp;
};

