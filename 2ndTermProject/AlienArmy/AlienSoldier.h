#pragma once
#include "../ArmyUnit.h"
class AlienSoldier :public ArmyUnit
{
public:
	AlienSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U = ArmyUnit::AS);
	virtual void AddAlienUnitToList(AlienArmy* passed_EA);
	virtual bool Attack();
};

