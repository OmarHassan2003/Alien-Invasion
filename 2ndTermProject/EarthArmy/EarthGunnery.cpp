#include "EarthGunnery.h"


EarthGunnery::EarthGunnery(Game* p, int HP, int pow, int ID_, int cap, int Tj)
	:ArmyUnit(p, HP, pow, ID_, cap, Tj)
{}

void EarthGunnery::AddEarthUnitToList(EarthArmy* passed_EA)
{
	passed_EA->AddInPriQueue(this);
}

void EarthGunnery::AddAlienUnitToList(AlienArmy* passed_AA)
{
}

bool EarthGunnery::Attack(ArmyUnit* AU0, ArmyUnit* AU1)
{
	bool flag = false;
	if (AU0)
	{
		AU0->SetHealth(AU0->GetHealth() - this->GetAttackCap());			
		flag = true;
	}
	if (AU1)
	{
		AU1->SetHealth(AU1->GetHealth() - this->GetAttackCap());
		flag = true;
	}
	return flag;
}

ostream& operator<<(ostream& COUT, EarthGunnery* Passed_AU)
{
	COUT << Passed_AU->GetID() << " ";
	return COUT;
}
