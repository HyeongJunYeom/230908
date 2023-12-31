#pragma once

#include "Space.h"

class CInn : public CSpace
{
public:
	CInn();
	~CInn() override;

public:
	void Initialize() override;
	void Update() override;
	void Release() override;
	void Render() const override;
};

