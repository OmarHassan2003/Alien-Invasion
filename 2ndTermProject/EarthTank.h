#pragma once
#include "ArmyUnit.h"
#include "EarthArmy/EarthArmy.h"
class EarthTank:public ArmyUnit
{
public:
	EarthTank(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U = ArmyUnit::ET);
	virtual void AddEarthUnitToList(EarthArmy* passed_EA);
	virtual bool Attack();
};

