#pragma once

#include "../Army.h"

class EarthSoldier;
class EarthGunnery;
class EarthTank;
class HealUnit;

class ArmyUnit;
class Game;

class EarthArmy :public Army
{
	Queue<EarthSoldier*> ES_Queue;
	priQueue<EarthGunnery*> EG_priQ;
	Stack<EarthTank*> ET_Stack;
	Stack<HealUnit*> HU_Stack;
public:
	EarthArmy();
	bool Attack();
	void PrintArmyInfo(); // Add HU
	/****************pick units from lists********************/
	bool pick_ES(EarthSoldier*& EPtr);
	bool pick_ET(EarthTank*& EPtr);
	bool pick_EG(EarthGunnery*& EPtr);
	bool pick_HU(HealUnit*& Eptr);
	/*****************peek units from list********************/
	bool peek_EG(EarthGunnery*& EPtr);  //Sounds Like It has no use
	/****************insert units to lists********************/
	bool AddUnit(ArmyUnit* passed_AU); // THE GENERAL ONE
	void AddInQueue(EarthSoldier* passed_AU);
	void AddInStack(EarthTank* passed_AU);
	void AddInPriQueue(EarthGunnery* passed_AU);
	void AddInHUStack(HealUnit* passed_HU);
	/*************************Check if Army has fallen down***********************/
	bool isCompromised();
	~EarthArmy();
};