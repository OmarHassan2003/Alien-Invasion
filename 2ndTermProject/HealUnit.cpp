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
		passed_EA->InsertHU(this);
	}
}

void HealUnit::AddAlienUnitToList(AlienArmy* passed_AA)
{
}

bool HealUnit::Attack(ArmyUnit* AU0, ArmyUnit* AU1)
{
	ArmyUnit* AU = nullptr;
	int pri = 0;
	for (int i = 0; i < this->GetAttackCap(); i++)
	{
		if (pGame->GetUML(AU, pri))
			if (AU->GetStepsInUML() <= 10)
				AU += (this->GetHealth() * this->GetPower()) / (100 * AU->GetHealth());
			else
				pGame->AddInKilledList(AU);
		else
			return false;
	}
}

ostream& operator<<(ostream& COUT, HealUnit* Passed_AU)
{
	if (Passed_AU != NULL)
	{
		COUT << Passed_AU->GetID() << " ";
		return COUT;
	}
}