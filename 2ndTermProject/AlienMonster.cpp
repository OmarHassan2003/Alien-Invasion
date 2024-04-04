#include "AlienMonster.h"

AlienMonster::AlienMonster()
	:ArmyUnit(0, 0, 0, 0, 0, 0, AM)
{
}

AlienMonster::AlienMonster(Game* p, int HP, int pow, int ID_, int cap, int _Tj)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, AM)
{
}

bool AlienMonster::Attack()
{
	return false;
}
