#pragma once
#include "../ArmyUnit.h"
#include "EarthSoldier.h"
#include "../EarthGunnery.h"
#include "../Queue/Queue.h"
#include "../priQueue.h"
#include "../Stack/Stack.h"

class EarthArmy
{
	Queue<EarthSoldier*> ES;
	priQueue<EarthGunnery*> EG;
public:
	EarthArmy();
	bool Attack();
	bool AddUnit(char u, int, int, int, int, int); //pass parameters as an array.
	void PrintArmyInfo();
};

