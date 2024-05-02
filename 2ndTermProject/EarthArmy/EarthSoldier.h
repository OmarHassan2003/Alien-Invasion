#pragma once
#include "../ArmyUnit.h"
#include "EarthArmy.h"

class EarthSoldier : public ArmyUnit
{
public:
	EarthSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U = ES);
	virtual void AddEarthUnitToList(EarthArmy* passed_EA);
	virtual void AddAlienUnitToList(AlienArmy* passed_AA);
	virtual bool Attack(); //PHASE2
	friend ostream& operator<<(ostream& COUT, EarthSoldier* Passed_AU);
};

