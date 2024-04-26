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

bool AlienSoldier::Attack(ArmyUnit* AU0, ArmyUnit* AU1)
{
	bool flag = 1;
	EarthSoldier* ES = nullptr;
	for (int i = 0; i < GetAttackCap(); i++)
		if (pGame->Get_ES(ES))
		{
			ES -= GetPower();
			if (ES->GetHealth() <= 0)
				pGame->AddInKilledList(ES);
			else if (ES->GetHealth() < 0.2 * ES->GetInitialH())
				pGame->AddToUML(ES, 0);
			else
			{
				// move to templist. //specisl one for each unit class or in GAME.
			}
		}
		else
			flag = 0; // no. of available units to be attacked less than the attack cap.

	return flag;
}

ostream& operator<<(ostream& COUT, AlienSoldier* Passed_AU)
{
	COUT << Passed_AU->GetID() << " ";
	return COUT;
}
