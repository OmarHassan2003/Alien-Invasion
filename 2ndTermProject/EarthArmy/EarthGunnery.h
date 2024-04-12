#pragma once

#include "../ArmyUnit.h"
#include "EarthArmy.h"

class EarthGunnery : public ArmyUnit
{
public:
	EarthGunnery(Game* p, int HP, int pow, int ID_, int cap, int Tj, Unit U = ArmyUnit::EG);
	virtual void AddEarthUnitToList(EarthArmy* passed_EA);
	virtual void AddAlienUnitToList(AlienArmy* passed_AA);
	virtual bool Attack();
	friend ostream& operator<<(ostream& COUT, EarthGunnery* Passed_AU);
};


