#pragma once

#include "../ArmyUnit.h"
#include "EarthArmy.h"

class EarthGunnery : public ArmyUnit
{
public:
	EarthGunnery(Game* p, int HP, int pow, int ID_, int cap, int Tj);
	virtual void AddEarthUnitToList(EarthArmy* passed_EA);
	virtual void AddAlienUnitToList(AlienArmy* passed_AA);
	//virtual bool Attack(ArmyUnit* AU0 = nullptr, ArmyUnit* AU1 = nullptr);
	friend ostream& operator<<(ostream& COUT, EarthGunnery* Passed_AU);
};


