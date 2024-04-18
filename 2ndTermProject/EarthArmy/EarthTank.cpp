#include "EarthTank.h"


EarthTank::EarthTank(Game* p, int HP, int pow, int ID_, int cap, int _Tj)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj)
{
}

void EarthTank::AddEarthUnitToList(EarthArmy* passed_EA)
{
	passed_EA->AddInStack(this);
}

void EarthTank::AddAlienUnitToList(AlienArmy* passed_AA)
{
}

bool EarthTank::Attack(ArmyUnit* AU0, ArmyUnit* AU1)
{
	return false;
}

ostream& operator<<(ostream& COUT, EarthTank* Passed_AU)
{
	COUT << Passed_AU->GetID() << " ";
	return COUT;
}
