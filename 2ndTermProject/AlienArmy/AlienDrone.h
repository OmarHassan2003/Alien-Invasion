#pragma once
#include "AlienArmy.h"
#include "../ArmyUnit.h"
class AlienDrone : public ArmyUnit
{
public:
	AlienDrone(Game* p, int HP, int pow, int ID_, int cap, int Tj, Unit U = AD);
	friend ostream& operator<<(ostream& COUT, AlienDrone* PAssed_AD);
	virtual bool Attack();
};

