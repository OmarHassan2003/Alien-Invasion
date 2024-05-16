#pragma once
#include "../ArmyUnit.h"
#include "EarthArmy.h"

class EarthSoldier : public ArmyUnit
{
	bool IsInfected = false;
	bool IsImmune = false;
public:
	EarthSoldier(Game* p, double HP, double pow, int ID_, int cap, int _Tj, Unit U = ES);
	virtual bool Attack(); //PHASE2
	void setInfected(bool inf);
	bool getInfected();
	void setImmune(bool imu);
	bool getImmune();
	friend ostream& operator<<(ostream& COUT, EarthSoldier* Passed_AU);
};

