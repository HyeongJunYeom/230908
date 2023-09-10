#include "pch.h"
#include "Armor.h"

CArmor::CArmor(int _iType)
	: CItem(_iType)
{
}

CArmor::~CArmor()
{
}

void CArmor::Render() const
{
	cout << "=====���� ����=====" << endl << endl;
	cout << "�̸�: " << Get_Name() << endl;
	cout << "����: " << Get_Hp() << endl;
	cout << "������: " << Get_Dura() << " / " << Get_MaxDura() << endl;
	cout << "����: " << Get_Gold() << endl << endl;
}

void CArmor::Initialize()
{
	Set_Attack(0);	Set_Dura(100);	Set_MaxDura(100);
	switch (m_iType)
	{
	case NORMAL_WEAPON:
		Set_Gold(100);		Set_Name("���� ����");			Set_Hp(30);
		break;

	case MAGIC_WEAPON:
		Set_Gold(200);		Set_Name("��ö ����");			Set_Hp(60);
		break;

	case RARE_WEAPON:
		Set_Gold(300);		Set_Name("�̽��� ����");		Set_Hp(90);
		break;

	case EPIC_WEAPON:
		Set_Gold(500);		Set_Name("Ÿ��ź�� ����");		Set_Hp(150);
		break;
	}
}
