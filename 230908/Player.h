#pragma once

#include "Creature.h"

class CPlayer : public CCreature
{
public:
	CPlayer() {}
	~CPlayer() override;

public:
	void		Release() override;
	void		Render() const override;

	void		Initialize();

public:
	void		Set_AddExp(int _iAdd);
	void		Set_MinExp(int _iMin);
	void		Set_AddHp(int _iAdd);
	void		Set_AddGold(int _iAdd);
	void		Set_MinGold(int _iMin);

protected:
	void		Level_Up();
	void		Input_Name();
	void		Select_Job();

public:
	int			Get_Level() const { return m_iLevel; }
	int			Get_NeedExp() const { return m_iNeedExp; }
	int			Get_Job() const { return m_iJob; }
	String		Get_JobString() const { return m_JobString; }

protected:
	void		Set_Level(int _iLevel) { m_iLevel = _iLevel; }
	void		Set_NeedExp(int _iNeedExp) { m_iNeedExp = _iNeedExp; }
	void		Set_Job(int _iJob) { m_iJob = _iJob; }
	void		Set_JobString(String _JobString) { m_JobString = _JobString; }
	void		Set_JobString(const char* _pJobString) { m_JobString = _pJobString; }

private:
	int		m_iLevel;
	int		m_iNeedExp;
	int		m_iJob;
	String	m_JobString;
};

