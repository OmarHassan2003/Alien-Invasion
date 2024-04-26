#include "EarthSoldier.h"
#include "../Game.h"

EarthSoldier::EarthSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj)
{
}

void EarthSoldier::AddEarthUnitToList(EarthArmy* passed_EA)
{
	if(passed_EA)
	{
		passed_EA->AddInQueue(this);
	}
}

void EarthSoldier::AddAlienUnitToList(AlienArmy* passed_AA)
{
}

bool EarthSoldier::Attack(ArmyUnit* AU0, ArmyUnit* AU1) //PHASE2
{
	bool flag = 1;
	AlienSoldier* AS = nullptr;
	for (int i = 0; i < GetAttackCap(); i++)
		if (pGame->Get_AS(AS))
		{
			AS -= GetPower();
			if (AS->GetHealth() <= 0)
				pGame->AddInKilledList(AS);
			else
			{
				// move to templist.
			}
		}
		else
			flag = 0; // no. of available units to be attacked less than the attack cap.

	return flag;
}

ostream& operator<<(ostream& COUT, EarthSoldier* Passed_AU)
{
	if (Passed_AU != NULL)
	{
		COUT << Passed_AU->GetID() << " ";
		return COUT;
	}
}