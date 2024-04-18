#include "AlienMonster.h"

AlienMonster::AlienMonster()
	:ArmyUnit(0, 0, 0, 0, 0, 0)
{
}

AlienMonster::AlienMonster(Game* p, int HP, int pow, int ID_, int cap, int _Tj)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj)
{
}

void AlienMonster::AddEarthUnitToList(EarthArmy* passed_EA)
{}

void AlienMonster::AddAlienUnitToList(AlienArmy* passed_AA)
{
	passed_AA->AddInAmArray(this);
}

bool AlienMonster::Attack(ArmyUnit* AU0, ArmyUnit* AU1)
{
	return false;
}

ostream& operator<<(ostream& COUT, AlienMonster* PAssed_AM)
{
	if (PAssed_AM)
	{
		COUT << PAssed_AM->GetID() << " ";
		return COUT;
	}
}
