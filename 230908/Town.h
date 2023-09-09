#pragma once

#include "Space.h"

class CTown : public CSpace
{
public:
	CTown();
	~CTown() override;

public:
	void Initialize() override;
	void Update() override;
	void Release() override;
	void Render() const override;
	
private:
	CSpace* m_pSpace;
};

