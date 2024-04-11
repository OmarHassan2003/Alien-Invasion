#include "EarthGunnery.h"


EarthGunnery::EarthGunnery(Game* p, int HP, int pow, int ID_, int cap, int Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, Tj, U)
{

}

void EarthGunnery::AddEarthUnitToList(EarthArmy* passed_EA)
{
	passed_EA->AddInPriQueue(this);
}

void EarthGunnery::AddAlienUnitToList(AlienArmy* passed_AA)
{
}

bool EarthGunnery::Attack()
{
	return false;
}

ostream& operator<<(ostream& COUT, EarthGunnery* Passed_AU)
{
	COUT << Passed_AU->GetID() << " ";
	return COUT;
}