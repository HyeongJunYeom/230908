#include "pch.h"
#include "Monster.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
}

void CMonster::Render() const
{
	cout << "===== ���� ���� =====" << endl << endl;

	cout << "�̸�: " << Get_Name() << endl;
	cout << "ü��: " << Get_Hp() << " / " << Get_MaxHp() << endl;
	cout << "���ݷ�: " << Get_Attack() << endl << endl;
}
