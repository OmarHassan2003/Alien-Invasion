#include "HealUnit.h"
#include "Game.h"

HealUnit::HealUnit(Game* p, int HP, int pow, int ID_, int cap, int _Tj)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj)
{
}

void HealUnit::AddEarthUnitToList(EarthArmy* passed_EA)
{
	if (passed_EA)
	{
		//passed_EA->AddInQueue(this);
		//AddInHU_Stack
	}
}

void HealUnit::AddAlienUnitToList(AlienArmy* passed_AA)
{
}

ostream& operator<<(ostream& COUT, HealUnit* Passed_AU)
{
	if (Passed_AU != NULL)
	{
		COUT << Passed_AU->GetID() << " ";
		return COUT;
	}
}