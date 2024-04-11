#pragma once
#include "../ArmyUnit.h"
#include "AlienArmy.h"
class AlienSoldier :public ArmyUnit
{
public:
	AlienSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U = ArmyUnit::AS);
	virtual void AddEarthUnitToList(EarthArmy* passed_EA);
	virtual void AddAlienUnitToList(AlienArmy* passed_AA);
	virtual bool Attack();
	friend ostream& operator<<(ostream& COUT, AlienSoldier* Passed_AU);
};

