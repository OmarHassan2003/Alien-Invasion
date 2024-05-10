#pragma once
#include "ArmyUnit.h"
#include "EarthArmy/EarthArmy.h"

class HealUnit : public ArmyUnit
{
public:
	HealUnit(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U = EH);
	virtual bool Attack();
	friend ostream& operator<<(ostream& COUT, EarthSoldier* Passed_AU);
};

