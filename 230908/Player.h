#pragma once

#include "Creature.h"
#include "Inventory.h"

class CPlayer : public CCreature
{
public:
	CPlayer() : m_pInven(nullptr), m_pArmor(nullptr), m_pWeapon(nullptr) {}
	~CPlayer() override;

public:
	void		Release() override;
	void		Render() const override;

	void		Initialize();

public:
	bool		Equip_Wepon(CObj* _pWeapon);
	bool		Equip_Armor(CObj* _pArmor);

	void		Inventory();

public:
	void		Set_AddExp(int _iAdd);
	void		Set_MinExp(int _iMin);
	void		Set_AddHp(int _iAdd);
	void		Set_AddGold(int _iAdd);
	void		Set_MinGold(int _iMin);
	void		Set_AddAtt(int _iAdd);
	void		Set_MinAtt(int _iMin); 
	void		Set_AddMaxHp(int _iAdd);
	void		Set_MinMaxHp(int _iMin);

	void		Set_LoadData(String _Name, String _JobString);
	void		Set_SaveData();

protected:
	void		Level_Up();
	void		Input_Name();
	void		Select_Job();

public:
	CObj*		Get_Weapon() const {return m_pWeapon;}
	CObj*		Get_Armor() const {return m_pArmor;}
	int			Get_Level() const { return m_iLevel; }
	int			Get_NeedExp() const { return m_iNeedExp; }
	int			Get_Job() const { return m_iJob; }
	String		Get_JobString() const { return m_JobString; }
	CInventory* Get_Inventory() { return m_pInven; }

protected:
	void		Set_JobString(String _JobString) { m_JobString = _JobString; }
	void		Set_JobString(const char* _pJobString) { m_JobString = _pJobString; }
	void		Set_Level(int _iLevel) { m_iLevel = _iLevel; }
	void		Set_NeedExp(int _iNeedExp) { m_iNeedExp = _iNeedExp; }
	void		Set_Job(int _iJob) { m_iJob = _iJob; }

private:
	int			m_iLevel;
	int			m_iNeedExp;
	int			m_iJob;
	String		m_JobString;
	CObj*		m_pWeapon;
	CObj*		m_pArmor;
	CInventory*	m_pInven;
};

