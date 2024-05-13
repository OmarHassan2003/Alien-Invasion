#pragma once
#include "Army.h";

class RandomGenerator;
class ArmyUnit;
#include "SaverUnit.h"
class AlliedArmy :public Army
{
	int Total_Gen_SU;
	bool Succesful_Attack;
	Queue<SaverUnit*> SU_Queue;

public:
	AlliedArmy();
	bool Attack();
	void PrintArmyInfo();
	/****************Get Counts of lists**********************/
	int SU_Count() const;
	int Total_SU_Count() const;
	/****************insert units to lists********************/
	bool AddUnit(ArmyUnit* passed_AU);
	void destroy_SU(Game* pGame);
	void AddInQueue(SaverUnit* passed_AU);
	~AlliedArmy();
};