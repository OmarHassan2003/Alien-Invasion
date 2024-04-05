#pragma once
#include "../Army.h"

class EarthGunnery;
class EarthTank;
class EarthSoldier;
class ArmyUnit;
class Game;

class EarthArmy :public Army
{
	Queue<EarthSoldier*> ES_Queue;
	priQueue<EarthGunnery*> EG_priQ;
	Stack<EarthTank*> ET_Stack;
public:
	EarthArmy();
	bool Attack();
	bool AddUnit(ArmyUnit* passed_AU);
	void PrintArmyInfo();

	//bool AddUnit(Game* pG, ArmyUnit*);
	void AddInStack(EarthTank* passed_AU);
	void AddInQueue(EarthSoldier* passed_AU);
	void AddInPriQueue(EarthGunnery* passed_AU);
};


