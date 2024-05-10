#pragma once
#include "../ArmyUnit.h"
#include "AlienArmy.h"
class AlienSoldier : public ArmyUnit
{
public:
	AlienSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U = AS);
	virtual bool Attack(); //PHASE2
	friend ostream& operator<<(ostream& COUT, AlienSoldier* Passed_AU);
};

