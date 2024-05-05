#pragma once
#include "AlienArmy.h"
#include "../ArmyUnit.h"
class AlienDrone : public ArmyUnit
{
public:
	AlienDrone(Game* p, int HP, int pow, int ID_, int cap, int Tj, Unit U = AD);
	virtual void AddEarthUnitToList(EarthArmy* passed_EA);
	virtual void AddAlienUnitToList(AlienArmy* passed_AA);
	virtual void Increment_E_Destructed_Units(EarthArmy* passed_EA);
	virtual void Increment_A_Destructed_Units(AlienArmy* passed_EA);
	friend ostream& operator<<(ostream& COUT, AlienDrone* PAssed_AD);
	virtual bool Attack();
};

