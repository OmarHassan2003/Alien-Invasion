#pragma once
#include "ArmyUnit.h"
class AlienSoldier :public ArmyUnit
{
public:
	AlienSoldier(Game* p, int HP, int pow, int ID_, int cap);
	virtual bool Attack();

};

