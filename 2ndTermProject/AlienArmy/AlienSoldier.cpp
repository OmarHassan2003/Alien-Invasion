#include "AlienSoldier.h"

AlienSoldier::AlienSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, U)
{
}

void AlienSoldier::AddEarthUnitToList(EarthArmy* passed_EA)
{
}

bool AlienSoldier::Attack()
{
	return false;
}
