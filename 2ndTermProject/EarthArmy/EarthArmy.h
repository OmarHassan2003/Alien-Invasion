#pragma once
#include "../ArmyUnit.h"
#include "EarthSoldier.h"
#include "../EarthTank.h"
#include "../EarthGunnery.h"
//class ArmyUnit;
//class EarthGunnery;
//class EarthTank;
//class EarthSoldier;
//class Game;
#include "../Queue/Queue.h"
#include "../priQueue.h"
#include "../Stack/Stack.h"

class EarthArmy
{
	Queue<EarthSoldier*> ES;
	priQueue<EarthGunnery*> EG;
	Stack<EarthTank*> ET;
public:
	EarthArmy();
	bool Attack();
	bool AddUnit(Game* pG, ArmyUnit*); //pass parameters as an array.
	void PrintArmyInfo();
};

