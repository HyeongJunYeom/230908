#pragma once

#include "Space.h"
#include "String.h"

class CTown : public CSpace
{
public:
	CTown();
	~CTown() override;

public:
	void		Initialize() override;
	void		Update() override;
	void		Release() override;
	void		Render() const override;

public:
	bool		Save_Game() const;
	
private:
	CSpace* m_pSpace;
};

