#pragma once
#include "../ArmyUnit.h"
#include "AlienArmy.h"
class AlienSoldier : public ArmyUnit
{
public:
	AlienSoldier(Game* p, double HP, double pow, int ID_, int cap, int _Tj, Unit U = AS);
	virtual bool Attack(); //PHASE2
	friend ostream& operator<<(ostream& COUT, AlienSoldier* Passed_AU);
};

