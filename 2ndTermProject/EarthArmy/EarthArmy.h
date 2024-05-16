#pragma once
#include "../Army.h"

class RandomGenerator;
class EarthSoldier;
class EarthGunnery;
class EarthTank;
class HealUnit;
class ArmyUnit;
class EarthArmy :public Army
{
	RandomGenerator* randgen;
	bool Won;
	bool IsAttack;
	Queue<EarthSoldier*> ES_Queue;
	priQueue<EarthGunnery*> EG_priQ;
	Stack<EarthTank*> ET_Stack;
	Stack<HealUnit*> HU_Stack;
	int Total_Gen_E_Units = 0;
	int Total_Gen_ES = 0;
	int Total_Gen_ET = 0;
	int Total_Gen_EG = 0;
	int Total_Gen_EH = 0;
	int Total_Healed = 0;
	int Total_Infected = 0;
public:
	EarthArmy();
	void SetRandGen(RandomGenerator* p);
	void IncInfectedES();
	int GetTotal_Infected();
	bool Attack();
	void PrintArmyInfo(); // Add HU
	void SetWon(bool p);
	bool GetWon() const;
	void SetIsAttack(bool p);
	bool GetIsAttack() const;
	void SpreadInfection();
	/****************pick units from lists********************/
	bool pick_ES(EarthSoldier*& EPtr);
	bool pick_ET(EarthTank*& EPtr);
	bool pick_EG(EarthGunnery*& EPtr);
	bool pick_HU(HealUnit*& Eptr);
	/****************Get Counts of lists**********************/
	int ES_Count() const;
	int ES_Infected_Count();
	int ET_Count() const;
	int EG_Count() const;
	int EH_Count() const;
	int Total_ES_Count() const;
	int Total_ET_Count() const;
	int Total_EG_Count() const;
	int Total_EH_Count() const;
	int Total_HealedCount() const;
	int Total_EarthUnits_Count() const;
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