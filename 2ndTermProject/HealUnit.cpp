#include "HealUnit.h"
#include "Game.h"

HealUnit::HealUnit(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, U)
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

bool HealUnit::Attack()
{
	bool flag = 1;
	ArmyUnit* AU = nullptr;
	int pri = 0;
	Queue<ArmyUnit*> EStemplist;
	Queue<ArmyUnit*> ETtemplist;

	for (int i = 0; i < this->GetAttackCap(); i++)
		if (pGame->Get_ES_UML(AU))
			if(AU)
				if (AU->GetStepsInUML() <= 10)
				{
					int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(AU->GetHealth()));
					AU->SetHealth(AU->GetHealth() + dmg);

					if (AU->GetHealth() > 0.2 * AU->GetInitialH())
					{
						pGame->Add_ES((EarthSoldier*)AU);
						AU->Set_StepsInUML(0);
					}
					else //still under 20% hp.
						EStemplist.enqueue(AU);
				}
				else
					pGame->AddInKilledList(AU);
		else if(pGame->Get_ET_UML(AU))
			if(AU)
				if (AU->GetStepsInUML() <= 10)
				{
					int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(AU->GetHealth()));
					AU->SetHealth(AU->GetHealth() + dmg);

					if (AU->GetHealth() > 0.2 * AU->GetInitialH())
					{
						pGame->Add_ET((EarthTank*)AU);
						AU->Set_StepsInUML(0);
					}
					else //still under 20% hp.
						ETtemplist.enqueue(AU);
				}
				else
					pGame->AddInKilledList(AU);
		else
			flag = 0; // no. of available units to be attacked less than the attack cap.

	while (EStemplist.dequeue(AU))
		pGame->AddToESUML(AU);
	while (ETtemplist.dequeue(AU))
		pGame->AddToETUML(AU);
	this->Set_Ta(pGame->Get_Tj());
	pGame->AddInKilledList(this); //KILL HU after attack.

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