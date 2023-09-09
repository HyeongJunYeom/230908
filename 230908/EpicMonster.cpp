#include "pch.h"
#include "EpicMonster.h"

void CEpicMonster::Initiallize()
{
	Set_Name("ø¿≈©");
	Set_Attack(10);
	Set_MaxHp(50);
	Set_Hp(Get_MaxHp());
	Set_Gold(30);
	Set_Exp(15);
}
