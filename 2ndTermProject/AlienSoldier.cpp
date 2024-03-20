#include "AlienSoldier.h"

AlienSoldier::AlienSoldier(Game* p, int HP, int pow, int ID_, int cap)
	:ArmyUnit(p, HP, pow, ID_, cap, AS)
{
}

bool AlienSoldier::Attack()
{
	return false;
}
