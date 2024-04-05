#pragma once
#include "../ArmyUnit.h"
#include "../EarthArmy/EarthArmy.h"

class EarthSoldier : public ArmyUnit
{
public:
	EarthSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U = ArmyUnit::ES);
	virtual void AddEarthUnitToList(EarthArmy* passed_EA);
	virtual bool Attack();
	
};
