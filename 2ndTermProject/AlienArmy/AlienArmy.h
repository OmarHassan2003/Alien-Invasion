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
	unsigned int Total_A_Units = 0;
	unsigned int Total_A_Destructed_Units = 0;
public:
	AlienArmy();
	bool Attack();
	void PrintArmyInfo();
	unsigned int Get_Total_A_Units() const;
	unsigned int Get_Total_Destructed_A_Units() const;
	void Increment_Total_A_Destructed_Units();
	/****************pick units from lists********************/
	bool pick_AS(AlienSoldier*& EPtr);
	bool pick_AM(AlienMonster*& passed_AM);
	bool pick_AD(AlienDrone*& passed_AD); //change to bool.
	bool pick_Rear_AD(AlienDrone*& passed_AD);
	/****************peek units from lists********************/
	bool peek_AD(AlienDrone*& passed_AD);
	bool peek_AD_Rear(AlienDrone*& passed_AD);
	bool peek_AM(AlienMonster*& passed_AM);
	/****************Get Counts of lists**********************/
	int AS_Count() const;
	int AD_Count() const;
	int AM_Count() const;
	/****************insert units to lists********************/
	bool AddUnit(ArmyUnit* passed_AU); // THE GENERAL ONE
	void AddInQueue(AlienSoldier* passed_AU);
	void AddInAmArray(AlienMonster* passed_AU);
	void AddInDoubleLinkedQueueQueue(AlienDrone* passed_AU);
	void AddInLinkedQueue_Front(AlienDrone* passed_AU);
	/*************************Check if Army has fallen down***********************/
	bool isCompromised();
	~AlienArmy();
};