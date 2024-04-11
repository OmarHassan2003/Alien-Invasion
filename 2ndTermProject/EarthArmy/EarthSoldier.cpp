#include "EarthSoldier.h"

EarthSoldier::EarthSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, U)
{
}

void EarthSoldier::AddEarthUnitToList(EarthArmy* passed_EA)
{
	passed_EA->AddInQueue(this);
}

void EarthSoldier::AddAlienUnitToList(AlienArmy* passed_AA)
{
}


bool EarthSoldier::Attack()
{
	return false;
}

ostream& operator<<(ostream& COUT, EarthSoldier* Passed_AU)
{
	if (Passed_AU != NULL)
	{
		COUT << Passed_AU->GetID() << " ";
		return COUT;
	}
}