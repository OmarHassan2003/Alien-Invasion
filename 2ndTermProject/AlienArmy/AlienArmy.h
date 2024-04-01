#pragma once
#include "../ArmyUnit.h"
#include "AlienSoldier.h"
#include "../Queue/Queue.h"
#include "../Stack/Stack.h"

class AlienArmy
{
	//Queue<AlienSoldier*> AS;
public:
	AlienArmy();
	bool Attack();
	bool AddUnit();
	void PrintArmyInfo();
};

