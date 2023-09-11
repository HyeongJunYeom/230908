#include "pch.h"
#include "Item.h"


CItem::CItem(int _iType) : m_iType(_iType)
{
}

CItem::~CItem()
{
	Release();
}

void CItem::Release()
{
}
