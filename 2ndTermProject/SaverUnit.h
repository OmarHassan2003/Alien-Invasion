#pragma once
#include "ArmyUnit.h"
class AlliedArmy;

class SaverUnit : public ArmyUnit
{
public:
	SaverUnit(Game* p, double HP, double pow, int ID_, int cap, int _Tj, Unit U = SU);
	virtual bool Attack(); //PHASE2
	friend ostream& operator<<(ostream& COUT, SaverUnit* Passed_AU);
};

