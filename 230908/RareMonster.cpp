#include "pch.h"
#include "RareMonster.h"

void CRareMonster::Initiallize()
{
	Set_Name("°íºí¸°");
	Set_Attack(7);
	Set_MaxHp(30);
	Set_Hp(Get_MaxHp());
	Set_Gold(20);
	Set_Exp(10);
}
