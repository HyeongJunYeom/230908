#include "pch.h"
#include "LegendMonster.h"

void CLegendMonster::Initiallize()
{
	Set_Name("µå·¡°ï");
	Set_Attack(15);
	Set_MaxHp(100);
	Set_Hp(Get_MaxHp());
	Set_Gold(50);
	Set_Exp(25);
}
