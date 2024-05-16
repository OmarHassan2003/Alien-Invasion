#pragma once
#include "ArmyUnit.h"
#include "EarthArmy/EarthArmy.h"

class HealUnit : public ArmyUnit
{
	int HealedUnitsCount = 0;
public:
	HealUnit(Game* p, double HP, double pow, int ID_, int cap, int _Tj, Unit U = EH);
	virtual bool Attack();
	friend ostream& operator<<(ostream& COUT, EarthSoldier* Passed_AU);
	int GetHealedCount();
};

