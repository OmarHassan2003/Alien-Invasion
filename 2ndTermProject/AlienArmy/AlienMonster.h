#pragma once
#include "../ArmyUnit.h"
#include "AlienArmy.h"

class AlienMonster :public ArmyUnit
{
public:
	AlienMonster();
	AlienMonster(Game* p, int HP, int pow, int ID_, int cap, int _Tj);
	virtual void AddEarthUnitToList(EarthArmy* passed_EA);
	virtual void AddAlienUnitToList(AlienArmy* passed_AA);
	friend ostream& operator<<(ostream& COUT, AlienMonster* PAssed_AM);
	virtual bool Attack();
};

