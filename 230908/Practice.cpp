#include "pch.h"
#include <vector>
#include <algorithm>

class CBase
{
public:
	CBase() : m_iNum1 (1){}
	~CBase(){}

	virtual void Render() const override { cout << m_iNum1 << endl; }

private:
	int		m_iNum1;

};

class CDerived : public CBase
{
public:
	CDerived() : m_iNum2(2) {}
	~CDerived(){}

	void		Render() const override { cout << m_iNum2 << endl; }
	void		Render2() const 
	{
		CBase::Render();
		Render();
	}

private:
	int		m_iNum2;
};

void main(void)
{
	CBase* obj1 = new CDerived();
	CBase* obj2 = new CDerived();
	CBase* obj3 = new CDerived();
	CBase* obj4 = new CDerived();
	CBase* obj5 = new CDerived();

	vector<CBase*> vecObj;
	vector<CBase*>::iterator iter;

	vecObj.reserve(3);

	vecObj.push_back(obj1);
	vecObj.push_back(obj2);
	vecObj.push_back(obj3);
	vecObj.push_back(obj4);
	vecObj.push_back(obj5);

	iter = vecObj.begin();

	for_each(vecObj.begin(), vecObj.end(), iter)


	return;
}