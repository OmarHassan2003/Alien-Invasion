#include "AlienMonster.h"

AlienMonster::AlienMonster()
	:ArmyUnit(0, 0, 0, 0, 0, 0, AM)
{
}

AlienMonster::AlienMonster(Game* p, int HP, int pow, int ID_, int cap, int _Tj)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, AM)
{
}

void AlienMonster::AddEarthUnitToList(EarthArmy* passed_EA)
{}

void AlienMonster::AddAlienUnitToList(AlienArmy* passed_EA)
{
	passed_EA->AddInDoubleLinkedQueueQueue(this);
}

bool AlienMonster::Attack()
{
	return false;
}
