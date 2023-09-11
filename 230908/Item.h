#pragma once

#include "Obj.h"

class CItem : public CObj
{
public:
	CItem(int _iType);
	~CItem() override;

public:
	void		Release() override;

	virtual void	Initialize() PURE;
	virtual void	Render() const PURE;

public:
	int		Get_Type() const { return m_iType; }
	int		Get_Dura() const { return m_iDura; }
	int		Get_MaxDura() const { return m_iMaxDura; }
	void	Set_Dura(int _iDura) { m_iDura = _iDura; }

protected:
	void	Set_MaxDura(int _iMaxDura) { m_iMaxDura = _iMaxDura; }

protected:
	const int		m_iType;
	int		m_iDura;
	int		m_iMaxDura;
};

