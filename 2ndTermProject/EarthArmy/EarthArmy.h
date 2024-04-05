#pragma once
#include "../ArmyUnit.h"
//#include "EarthSoldier.h"
//#include "../EarthTank.h"
//#include "../EarthGunnery.h"
//class ArmyUnit;
class EarthGunnery;
class EarthTank;
class EarthSoldier;
//class Game;
#include "../Queue/Queue.h"
#include "../priQueue.h"
#include "../Stack/Stack.h"

class EarthArmy
{
	Queue<EarthSoldier*> ES_Queue;
	priQueue<EarthGunnery*> EG_priQ;
	Stack<EarthTank*> ET_Stack;
public:
	EarthArmy();
	bool Attack();
	//bool AddUnit(Game* pG, ArmyUnit*);
	void AddInStack(EarthTank* passed_AU);
	void AddInQueue(EarthSoldier* passed_AU);
	void AddInPriQueue(EarthGunnery* passed_AU);
	bool AddUnit(ArmyUnit* passed_AU); //pass parameters as an array.
	void PrintArmyInfo();
};

