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
	//bool Attack(); phase 2
	bool AddUnit(ArmyUnit* passed_AU);
	void PrintArmyInfo();
	/****************pick units from lists********************/
	bool pick_ES(EarthSoldier*& EPtr);
	bool pick_EG(EarthGunnery*& EPtr);
	bool pick_ET(EarthTank*& EPtr);
	/****************insert units from lists********************/
	void InsertES(EarthSoldier* passed_ES);
	void InsertEG(EarthGunnery* passed_EG);
	void InsertET(EarthTank* passed_ET);
	/*************************ADD Units***************************/
	void AddInStack(EarthTank* passed_AU);
	void AddInQueue(EarthSoldier* passed_AU);
	void AddInPriQueue(EarthGunnery* passed_AU);
	/*************************Check if Army has fallen down***********************/
	bool isCompromised();
	~EarthArmy();
};


