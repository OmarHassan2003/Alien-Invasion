#pragma once
#include "../ArmyUnit.h"

class EarthSoldier : public ArmyUnit
{
public:
	EarthSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U = ArmyUnit::ES);
	virtual bool Attack();
	
};
