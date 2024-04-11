#pragma once
#include "../Army.h"


class AlienSoldier;
class AlienDrone;
class AlienMonster;

class ArmyUnit;
class Game;

class AlienArmy :public Army
{
	int AM_Count = 0;
	Queue<AlienSoldier*> AS_Queue;
	DoubleLinkedQueue<AlienDrone*> AD_DQueue;
	AlienMonster* AM[1000];
public:
	AlienArmy();
	bool Attack();
	bool AddUnit(ArmyUnit* passed_AU);
	void PrintArmyInfo();
	/****************pick units from lists********************/
	AlienSoldier* pick_AS();
	AlienMonster* pick_AM();
	AlienDrone* pick_AD(int x);
	/****************insert units from lists********************/
	void InsertAS(AlienSoldier* passed_AS);
	void InsertAD(AlienDrone* passed_AD);
	void InsertAM(AlienMonster* passed_AM);
	//bool AddUnit(Game* pG, ArmyUnit* AU); //pass parameters as an array.
	void AddInQueue(AlienSoldier* passed_AU);
	void AddInDoubleLinkedQueueQueue(AlienDrone* passed_AU);
	void AddInAmArray(AlienMonster* passed_AU);
	//int AM_Count();
	AlienMonster* randAM();
	//int RETAMCOUNT();
};

