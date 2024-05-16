#pragma once

#include "../ArmyUnit.h"
#include "EarthArmy.h"

class EarthGunnery : public ArmyUnit
{
public:
	EarthGunnery(Game* p, double HP, double pow, int ID_, int cap, int Tj, Unit U = EG);
	virtual bool Attack();
	friend ostream& operator<<(ostream& COUT, EarthGunnery* Passed_AU);
};


