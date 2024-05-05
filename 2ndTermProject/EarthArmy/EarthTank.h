#pragma once
#include "../ArmyUnit.h"
#include "EarthArmy.h"

class EarthTank:public ArmyUnit
{
public:
	EarthTank(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U = ET);
	virtual void AddEarthUnitToList(EarthArmy* passed_EA);
	virtual void AddAlienUnitToList(AlienArmy* passed_AA);
	virtual void Increment_E_Destructed_Units(EarthArmy* passed_EA);
	virtual void Increment_A_Destructed_Units(AlienArmy* passed_EA);
	virtual bool Attack();
	friend ostream& operator<<(ostream& COUT, EarthTank* Passed_AU);
};


