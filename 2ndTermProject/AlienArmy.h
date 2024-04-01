#pragma once
#include "ArmyUnit.h"
#include "AlienSoldier.h"
#include "Queue.h"
#include "Stack.h"

class AlienArmy
{
	//Queue<AlienSoldier*> AS;
public:
	AlienArmy();
	bool Attack();
	bool AddUnit();
	void PrintArmyInfo();
};

