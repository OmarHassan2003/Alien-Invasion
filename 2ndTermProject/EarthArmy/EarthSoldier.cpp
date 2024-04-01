#include "EarthSoldier.h"

EarthSoldier::EarthSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, ES)
{
}

bool EarthSoldier::Attack()
{
	return false;
}

