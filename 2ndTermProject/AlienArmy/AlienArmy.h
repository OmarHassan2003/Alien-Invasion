#pragma once
#include "../Army.h"

class AlienSoldier;
class AlienDrone;
class AlienMonster;
class ArmyUnit;
class Game;

class AlienArmy :public Army
{
	Queue<AlienSoldier*> AS_Queue;
	DoubleLinkedQueue<AlienDrone*> AD_DQueue;
	AlienMonster* AM[1000];
public:
	AlienArmy();
	bool Attack();
	bool AddUnit(ArmyUnit* passed_AU);
	void PrintArmyInfo();
	
	//bool AddUnit(Game* pG, ArmyUnit* AU); //pass parameters as an array.
	void AddInQueue(AlienSoldier* passed_AU);
	void AddInDoubleLinkedQueueQueue(AlienDrone* passed_AU);
	void AddInAmArray(AlienMonster* passed_AU);
};

