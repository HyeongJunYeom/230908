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
	cout << "===== 몬스터 정보 =====" << endl << endl;

	cout << "이름: " << Get_Name() << endl;
	cout << "체력: " << Get_Hp() << " / " << Get_MaxHp() << endl;
	cout << "공격력: " << Get_Attack() << endl << endl;
}
