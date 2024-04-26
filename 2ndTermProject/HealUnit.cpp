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
		passed_EA->AddInHUStack(this);
	}
}

void HealUnit::AddAlienUnitToList(AlienArmy* passed_AA)
{
}

bool HealUnit::Attack(ArmyUnit* AU0, ArmyUnit* AU1)
{
	bool flag = 1;
	ArmyUnit* AU = nullptr;
	int pri = 0;
	priQueue<ArmyUnit*> templist;
	for (int i = 0; i < this->GetAttackCap(); i++)
		if (pGame->GetUML(AU, pri))
			if (AU->GetStepsInUML() <= 10)
			{
				AU += ((this->GetHealth() * this->GetPower()) / (100 * AU->GetHealth()));
				if (AU->GetHealth() > 0.2 * AU->GetInitialH())
					if (pri == -1)
					{
						//Add to Tanklist 
						AU->Set_StepsInUML(0);
					}
					else
					{
						//Add to ES_list
						AU->Set_StepsInUML(0);
					}
				else //still under 20% hp.
					templist.enqueue(AU, pri);
			}
			else
				pGame->AddInKilledList(AU);
		else
			flag = 0; // no. of available units to be attacked less than the attack cap.

	while (templist.dequeue(AU, pri))
		pGame->AddToUML(AU, pri);
	
	return flag;
}

ostream& operator<<(ostream& COUT, HealUnit* Passed_AU)
{
	if (Passed_AU != NULL)
	{
		COUT << Passed_AU->GetID() << " ";
		return COUT;
	}
}