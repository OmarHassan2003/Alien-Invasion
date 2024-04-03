#pragma once
#include "ArmyUnit.h"

class AlienDrone : public ArmyUnit
{
public:
	AlienDrone(Game* p, int HP, int pow, int ID_, int cap, int Tj, Unit U = ArmyUnit::AS);
	virtual bool Attack();
};

