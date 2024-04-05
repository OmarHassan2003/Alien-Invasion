#pragma once
#include "../Army.h"

class AlienSoldier;
class AlienDrone;
class AlienMonster;
class ArmyUnit;
class Game;

class AlienArmy :public Army
{
	Queue<AlienSoldier*> AS;
	DoubleLinkedQueue<AlienDrone*> AD;
	AlienMonster* AM[1000];
public:
	AlienArmy();
	bool Attack();
	bool AddUnit(ArmyUnit* passed_AU);
	void PrintArmyInfo();
	
	//bool AddUnit(Game* pG, ArmyUnit* AU); //pass parameters as an array.
};

