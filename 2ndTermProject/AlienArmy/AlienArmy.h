#pragma once
//#include "../ArmyUnit.h"
//#include "AlienSoldier.h"
class AlienSoldier;
class AlienDrone;
class AlienMonster;
//#include "../AlienDrone.h"
//#include "../AlienMonster.h"
#include "../Queue/Queue.h"
#include "../Stack/Stack.h"

class AlienArmy
{
	Queue<AlienSoldier*> AS;
	DoubleLinkedQueue<AlienDrone*> AD;
	AlienMonster* AM[1000];
public:
	AlienArmy();
	bool Attack();
	bool AddUnit(Game* pG, char u, int, int, int, int, int); //pass parameters as an array.
	void PrintArmyInfo();
};

