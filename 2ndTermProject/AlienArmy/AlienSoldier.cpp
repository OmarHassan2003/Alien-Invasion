#include "AlienSoldier.h"

AlienSoldier::AlienSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, AS)
{
}

bool AlienSoldier::Attack()
{
	return false;
}
