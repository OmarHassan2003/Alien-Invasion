#pragma once
#include "../ArmyUnit.h"
#include "AlienArmy.h"

class AlienMonster :public ArmyUnit
{
public:
	AlienMonster(Game* p, double HP, double pow, int ID_, int cap, int _Tj, Unit U = AM);
	friend ostream& operator<<(ostream& COUT, AlienMonster* PAssed_AM);
	virtual bool Attack();
};

