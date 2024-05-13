#include "SaverUnit.h"

SaverUnit::SaverUnit(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, U)
{
}

bool SaverUnit::Attack()
{
	return false;
}

ostream& operator<<(ostream& COUT, SaverUnit* Passed_AU)
{
	if (Passed_AU != NULL)
	{
		COUT << Passed_AU->GetID() << " ";
		return COUT;
	}
}