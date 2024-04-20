#include "AlienSoldier.h"
#include "../Game.h"

AlienSoldier::AlienSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj)
{
}

void AlienSoldier::AddEarthUnitToList(EarthArmy* passed_EA)
{
}

void AlienSoldier::AddAlienUnitToList(AlienArmy* passed_AA)
{
	if(passed_AA)
	{
		passed_AA->AddInQueue(this);
	}
}

ostream& operator<<(ostream& COUT, AlienSoldier* Passed_AU)
{
	COUT << Passed_AU->GetID() << " ";
	return COUT;
}
