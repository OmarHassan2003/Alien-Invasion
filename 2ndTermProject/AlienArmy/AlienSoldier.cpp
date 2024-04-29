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
	Queue<EarthSoldier*> templist;
	for (int i = 0; i < GetAttackCap(); i++)
		if (pGame->Get_ES(ES))
		{
			if (ES->Get_Ta() == 0)
				ES->Set_Ta(pGame->Get_Tj());
			
			ES -= int(GetPower() * GetHealth() / (100 * sqrt(ES->GetHealth())));

			if (ES->GetHealth() <= 0)
				pGame->AddInKilledList(ES);
			else if (ES->GetHealth() < 0.2 * ES->GetInitialH())
				pGame->AddToUML(ES, 0);
			else
				templist.enqueue(ES);
		}
		else
		{
			flag = 0;
			break;
		}
	while (templist.dequeue(ES))
		pGame->Add_ES(ES);
	return flag;
}

ostream& operator<<(ostream& COUT, AlienSoldier* Passed_AU)
{
	COUT << Passed_AU->GetID() << " ";
	return COUT;
}
