#pragma once
#include "../ArmyUnit.h"
#include "../AlienArmy/AlienArmy.h"

class AlienMonster :public ArmyUnit
{
public:
	AlienMonster();
	AlienMonster(Game* p, int HP, int pow, int ID_, int cap, int _Tj);
	virtual void AddEarthUnitToList(EarthArmy* passed_EA);
	virtual void AddAlienUnitToList(AlienArmy* passed_AA);
	virtual bool Attack();
};

