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
	cout << "=====���� ����=====" << endl << endl;
	cout << "�̸�: " << Get_Name() << endl;
	cout << "���ݷ�: " << Get_Attack() << endl;
	cout << "������: " << Get_Dura() << " / " << Get_MaxDura() << endl;
	cout << "����: " << Get_Gold() << endl << endl;
}

void CWeapon::Initialize()
{
	Set_Hp(0);	Set_Dura(100);	Set_MaxDura(100);
	switch (m_iType)
	{
	case NORMAL_WEAPON:
		Set_Gold(100);		Set_Name("���� ��");			Set_Attack(3);
		break;

	case MAGIC_WEAPON:
		Set_Gold(200);		Set_Name("��ö ��");			Set_Attack(6);
		break;

	case RARE_WEAPON:
		Set_Gold(300);		Set_Name("�̽��� ��");		Set_Attack(9);
		break;

	case EPIC_WEAPON:
		Set_Gold(500);		Set_Name("Ÿ��ź�� ��");		Set_Attack(15);
		break;
	}
}
