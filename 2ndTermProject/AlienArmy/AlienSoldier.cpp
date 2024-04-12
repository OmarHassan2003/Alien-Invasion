#include "AlienSoldier.h"

AlienSoldier::AlienSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, U)
{
}

void AlienSoldier::AddEarthUnitToList(EarthArmy* passed_EA)
{
}

void AlienSoldier::AddAlienUnitToList(AlienArmy* passed_AA)
{
	passed_AA->AddInQueue(this);
}

bool AlienSoldier::Attack()
{
	return false;
}

ostream& operator<<(ostream& COUT, AlienSoldier* Passed_AU)
{
	COUT << Passed_AU->GetID() << " ";
	return COUT;
}
