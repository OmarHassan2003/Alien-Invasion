#include "HealUnit.h"
#include "Game.h"

HealUnit::HealUnit(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, U)
{
}

bool HealUnit::Attack()
{
	bool flag = false;
	bool healed = 0;
	ArmyUnit* AU = nullptr;
	int pri = 0;
	Queue<ArmyUnit*> EStemplist;
	Queue<ArmyUnit*> ETtemplist;
	for (int i = 0; i < this->GetAttackCap(); i++)
		if (pGame->Get_ES_UML(AU))
		{
			if (AU)
			{
				int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(AU->GetHealth()));
				AU->SetHealth(AU->GetHealth() + dmg);
				flag = true;
				healed = 1;
				if (AU->GetHealth() >= 0.2 * AU->GetInitialH())
				{
					pGame->Add_ES((EarthSoldier*)AU);
					AU->Set_StepsInUML(0);
				}
				else //still under 20% hp.
					EStemplist.enqueue(AU);
			}

		}
		else if (pGame->Get_ET_UML(AU))
		{
			if (AU)
			{
				int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(AU->GetHealth()));
				AU->SetHealth(AU->GetHealth() + dmg);
				flag = true;
				healed = 1;
				if (AU->GetHealth() >= 0.2 * AU->GetInitialH())
				{
					pGame->Add_ET((EarthTank*)AU);
					AU->Set_StepsInUML(0);
				}
				else //still under 20% hp.
					ETtemplist.enqueue(AU);
			}
		}
		else
			break;// no. of available units to be attacked less than the attack cap.

	while (EStemplist.dequeue(AU))
		pGame->AddToESUML(AU);
	while (ETtemplist.dequeue(AU))
		pGame->AddToETUML(AU);

	this->Set_Ta(pGame->Get_Tj());

	if (healed)
		pGame->AddInKilledList(this); //KILL HU after healing.
	else
		flag = false; //return back if hasn't healed.
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