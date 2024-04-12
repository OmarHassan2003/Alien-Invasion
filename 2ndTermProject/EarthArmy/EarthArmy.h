#pragma once

#include "../Army.h"

class EarthSoldier;
class EarthGunnery;
class EarthTank;

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
	/****************pick units from lists********************/
	bool pick_ES(EarthSoldier*& EPtr);
	EarthGunnery* pick_EG();
	EarthTank* pick_ET();
	/****************insert units from lists********************/
	void InsertES(EarthSoldier* passed_ES);
	void InsertEG(EarthGunnery* passed_EG);
	void InsertET(EarthTank* passed_ET);
	//bool AddUnit(Game* pG, ArmyUnit*);
	void AddInStack(EarthTank* passed_AU);
	void AddInQueue(EarthSoldier* passed_AU);
	void AddInPriQueue(EarthGunnery* passed_AU);
};


