#pragma once
#include "ArmyUnit.h"
class AlienMonster :public ArmyUnit
{
public:
	AlienMonster();
	AlienMonster(Game* p, int HP, int pow, int ID_, int cap, int _Tj);
	virtual void AddAlienUnitToList(AlienArmy* passed_EA);
	virtual bool Attack();
};
