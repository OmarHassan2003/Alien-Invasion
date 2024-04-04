#pragma once
#include "EarthSoldier.h"
#include "../EarthGunnery.h"
#include "../Queue/Queue.h"
#include "../EarthTank.h"
#include "../priQueue.h"
#include "../Stack/Stack.h"
#include "../Game.h"

class EarthArmy
{
	Queue<EarthSoldier*> ES;
	priQueue<EarthGunnery*> EG;
	Stack<EarthTank*> ET;
public:
	EarthArmy();
	bool Attack();
	bool AddUnit(Game* pG, char u, int, int, int, int, int); //pass parameters as an array.
	void PrintArmyInfo();
};

