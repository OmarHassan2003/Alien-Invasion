#pragma once
#include "ArmyUnit.h"
class EarthSoldier :public ArmyUnit
{
public:
	EarthSoldier(Game* p, int HP, int pow, int ID_, int cap);
	virtual bool Attack();
	
};
