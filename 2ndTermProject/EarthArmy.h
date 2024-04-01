#pragma once
#include "ArmyUnit.h"
#include "EarthSoldier.h"
#include "Queue.h"
#include "Stack.h"

class EarthArmy
{
	//Queue<EarthSoldier*> ES;
public:
	EarthArmy();
	bool Attack();
	bool AddUnit();
	void PrintArmyInfo();
};

