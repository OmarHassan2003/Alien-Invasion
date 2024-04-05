#pragma once
#include "ArmyUnit.h"
class EarthGunnery : public ArmyUnit
{
public:
	EarthGunnery(Game* p, int HP, int pow, int ID_, int cap, int Tj, Unit U = ArmyUnit::EG);
	virtual bool Attack();
};

