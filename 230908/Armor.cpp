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
	cout << "=====°©¿Ê Á¤º¸=====" << endl << endl;
	cout << "ÀÌ¸§: " << Get_Name() << endl;
	cout << "¹æ¾î·Â: " << Get_Hp() << endl;
	cout << "³»±¸µµ: " << Get_Dura() << " / " << Get_MaxDura() << endl;
	cout << "°¡°Ý: " << Get_Gold() << endl << endl;
}

void CArmor::Initialize()
{
	Set_Attack(0);	Set_Dura(100);	Set_MaxDura(100);
	switch (m_iType)
	{
	case NORMAL_ARMOR:
		Set_Gold(100);		Set_Name("³ª¹« °©¿Ê");			Set_Hp(30);
		break;

	case MAGIC_ARMOR:
		Set_Gold(200);		Set_Name("°­Ã¶ °©¿Ê");			Set_Hp(60);
		break;

	case RARE_ARMOR:
		Set_Gold(300);		Set_Name("¹Ì½º¸± °©¿Ê");		Set_Hp(90);
		break;

	case EPIC_ARMOR:
		Set_Gold(500);		Set_Name("Å¸ÀÌÅºÀÇ °©¿Ê");		Set_Hp(150);
		break;
	}
}
