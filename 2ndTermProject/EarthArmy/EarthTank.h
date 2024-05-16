#pragma once
#include "../ArmyUnit.h"
#include "EarthArmy.h"

class EarthTank:public ArmyUnit
{
public:
	EarthTank(Game* p, double HP, double pow, int ID_, int cap, int _Tj, Unit U = ET);
	virtual bool Attack();
	friend ostream& operator<<(ostream& COUT, EarthTank* Passed_AU);
};


