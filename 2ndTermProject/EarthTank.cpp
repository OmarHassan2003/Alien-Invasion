#include "EarthTank.h"

EarthTank::EarthTank(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, U)
{
}

void EarthTank::AddEarthUnitToList(EarthArmy* passed_EA)
{
	passed_EA->AddInStack(this);
}

bool EarthTank::Attack()
{
	return false;
}
