#pragma once

#include "String.h"
#include "Define.h"

class CObj
{
public:
	CObj() {}
	CObj(String _name, int _iHp, int _iAttack, int _iGold)
		: m_Name(_name), m_iHp(_iHp), m_iAttack(_iAttack), m_iGold(_iGold)
	{ }
	virtual ~CObj()
	{
		Release();
	}

	virtual void Release() {}

	virtual void Render() const PURE;

protected:
	void		Set_Name(String _name)
	{
		m_Name = _name;
	}
	void		Set_Name(const char* _pName)
	{
		m_Name = _pName;
	}
	void		Set_Hp(int _iHp)
	{
		if (0 > _iHp)
		{
			m_iHp = 0;
			return;
		}

		m_iHp = _iHp;
	}
	void		Set_Attack(int _iAttack)
	{
		if (0 > _iAttack)
		{
			m_iAttack = 0;
			return;
		}
		m_iAttack = _iAttack;
	}
	void		Set_Gold(int _iGold)
	{
		if (0 > _iGold)
		{
			m_iGold = 0;
			return;
		}
		m_iGold = _iGold;
	}

public:
	String		Get_Name() const { return m_Name; }
	int		Get_Hp() const { return m_iHp; }
	int		Get_Attack() const { return m_iAttack; }
	int		Get_Gold() const { return m_iGold; }

private:
	String m_Name;
	int m_iHp;
	int m_iAttack;
	int m_iGold;
};

