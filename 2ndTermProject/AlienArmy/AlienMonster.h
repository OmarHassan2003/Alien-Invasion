#pragma once
#include "../ArmyUnit.h"
#include "AlienArmy.h"

class AlienMonster :public ArmyUnit
{
public:
	AlienMonster(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U = AM);
	virtual void AddEarthUnitToList(EarthArmy* passed_EA);
	virtual void AddAlienUnitToList(AlienArmy* passed_AA);
	virtual void Increment_E_Destructed_Units(EarthArmy* passed_EA);
	virtual void Increment_A_Destructed_Units(AlienArmy* passed_EA);
	friend ostream& operator<<(ostream& COUT, AlienMonster* PAssed_AM);
	virtual bool Attack();
};

