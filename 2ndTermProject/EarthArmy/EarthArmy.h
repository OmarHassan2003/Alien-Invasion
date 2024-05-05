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
	unsigned int Total_E_Units = 0;
	unsigned int Total_E_Destructed_Units = 0;
public:
	EarthArmy();
	bool Attack();
	void PrintArmyInfo(); // Add HU
	unsigned int Get_Total_E_Units() const;
	unsigned int Get_Total_E_Destructed_Units() const;
	void Increment_Total_E_Destructed_Units();
	/****************pick units from lists********************/
	bool pick_ES(EarthSoldier*& EPtr);
	bool pick_ET(EarthTank*& EPtr);
	bool pick_EG(EarthGunnery*& EPtr);
	bool pick_HU(HealUnit*& Eptr);
	/****************Get Counts of lists**********************/
	int ES_Count() const;
	int ET_Count() const;
	int EG_Count() const;
	int EH_Count() const;
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