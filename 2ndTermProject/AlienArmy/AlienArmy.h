#pragma once
#include "../Army.h"
#include "../RandomGenerator/RandomGenerator.h"

class AlienSoldier;
class AlienDrone;
class AlienMonster;

class ArmyUnit;
class Game;

class AlienArmy :public Army
{
	Queue<AlienSoldier*> AS_Queue;
	DoubleLinkedQueue<AlienDrone*> AD_DQueue;
	DynamicArray<AlienMonster*> AM;
public:
	AlienArmy();
	bool Attack();
	bool AddUnit(ArmyUnit* passed_AU);
	void PrintArmyInfo();
	/****************pick units from lists********************/
	bool pick_AS(AlienSoldier*& EPtr); 
	bool pick_AM(AlienMonster*& passed_AM);
	bool pick_AD(AlienDrone*& passed_AD);
	AlienSoldier* Remove_AS();
	bool pick_Rear_AD(AlienDrone*& passed_AD);
	/****************insert units from lists********************/
	void InsertAS(AlienSoldier* passed_AS);
	void InsertAD(AlienDrone* passed_AD);
	void InsertAM(AlienMonster* passed_AM);
	void AddInQueue(AlienSoldier* passed_AU);
	void AddInDoubleLinkedQueueQueue(AlienDrone* passed_AU);
	void AddInAmArray(AlienMonster* passed_AU);
	bool isComromised();
	~AlienArmy();
};

