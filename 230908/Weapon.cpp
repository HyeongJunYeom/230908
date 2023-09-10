#include "pch.h"
#include "Weapon.h"

CWeapon::CWeapon(int _iType)
	: CItem(_iType)
{
}

CWeapon::~CWeapon()
{
}

void CWeapon::Render() const
{
	cout << "=====무기 정보=====" << endl << endl;
	cout << "이름: " << Get_Name() << endl;
	cout << "공격력: " << Get_Attack() << endl;
	cout << "내구도: " << Get_Dura() << " / " << Get_MaxDura() << endl;
	cout << "가격: " << Get_Gold() << endl << endl;
}

void CWeapon::Initialize()
{
	Set_Hp(0);	Set_Dura(100);	Set_MaxDura(100);
	switch (m_iType)
	{
	case NORMAL_WEAPON:
		Set_Gold(100);		Set_Name("나무 검");			Set_Attack(3);
		break;

	case MAGIC_WEAPON:
		Set_Gold(200);		Set_Name("강철 검");			Set_Attack(6);
		break;

	case RARE_WEAPON:
		Set_Gold(300);		Set_Name("미스릴 검");		Set_Attack(9);
		break;

	case EPIC_WEAPON:
		Set_Gold(500);		Set_Name("타이탄의 검");		Set_Attack(15);
		break;
	}
}
