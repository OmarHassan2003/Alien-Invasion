#pragma once
#include "AlienArmy.h"
#include "../ArmyUnit.h"
class AlienDrone : public ArmyUnit
{
public:
	AlienDrone(Game* p, int HP, int pow, int ID_, int cap, int Tj);
	virtual void AddEarthUnitToList(EarthArmy* passed_EA);
	virtual void AddAlienUnitToList(AlienArmy* passed_AA);
	friend ostream& operator<<(ostream& COUT, AlienDrone* PAssed_AD);
	virtual bool Attack(ArmyUnit* AU0 = nullptr, ArmyUnit* AU1 = nullptr);
};

