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

bool EarthSoldier::Attack() //PHASE2
{
	bool flag = 1;
	AlienSoldier* AS = nullptr;
	Queue<AlienSoldier*> templist;
	for (int i = 0; i < GetAttackCap(); i++)
		if (pGame->Get_AS(AS))
		{
			AS->SetHealth(AS->GetHealth() - GetPower());
			if (AS->GetHealth() <= 0)
				pGame->AddInKilledList(AS);
			else
				templist.enqueue(AS);
		}
		else
		{
			flag = 0;
			break;
		}
	while (templist.dequeue(AS))
		pGame->Add_AS(AS);
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