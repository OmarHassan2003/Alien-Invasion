#include "EarthSoldier.h"

EarthSoldier::EarthSoldier(Game* p, int HP, int pow, int ID_, int cap)
	:ArmyUnit(p,HP,pow,ID_,cap,ES)
{
}

bool EarthSoldier::Attack()
{
	return false;
}

