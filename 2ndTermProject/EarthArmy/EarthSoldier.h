#pragma once
#include "../ArmyUnit.h"
#include "EarthArmy.h"

class EarthSoldier : public ArmyUnit
{
public:
	EarthSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U = ES);
	virtual void AddEarthUnitToList(EarthArmy* passed_EA);
	virtual void AddAlienUnitToList(AlienArmy* passed_AA);
	virtual void Increment_E_Destructed_Units(EarthArmy* passed_EA);
	virtual void Increment_A_Destructed_Units(AlienArmy* passed_EA);
	virtual bool Attack(); //PHASE2
	friend ostream& operator<<(ostream& COUT, EarthSoldier* Passed_AU);
};

