#pragma once
#include "../Army.h"
class AlienSoldier;
class AlienDrone;
class AlienMonster;
class ArmyUnit;

class AlienArmy :public Army
{
	bool Won;
	bool IsAttack;
	Queue<AlienSoldier*> AS_Queue;
	DoubleLinkedQueue<AlienDrone*> AD_DQueue;
	DynamicArray<AlienMonster*> AM;
	int Total_Gen_A_Units = 0;
	int Total_Gen_AS = 0;
	int Total_Gen_AM = 0;
	int Total_Gen_AD = 0;
public:
	AlienArmy();
	bool Attack();
	void PrintArmyInfo();
	void SetWon(bool p);
	bool GetWon() const;
	void SetIsAttack(bool p);
	bool GetIsAttack() const;
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
	int Total_AS_Count() const;
	int Total_AM_Count() const;
	int Total_AD_Count() const;
	int Total_AlienUnits_Count() const;
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