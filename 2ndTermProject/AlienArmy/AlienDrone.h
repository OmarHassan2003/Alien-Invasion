#pragma once
#include "../AlienArmy/AlienArmy.h"
#include "../ArmyUnit.h"
class AlienDrone : public ArmyUnit
{
public:
	AlienDrone(Game* p, int HP, int pow, int ID_, int cap, int Tj, Unit U = ArmyUnit::AS);
	virtual void AddEarthUnitToList(EarthArmy* passed_EA);
	virtual void AddAlienUnitToList(AlienArmy* passed_AA);
	virtual bool Attack();
};

