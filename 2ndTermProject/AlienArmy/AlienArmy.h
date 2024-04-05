#pragma once
#include "../ArmyUnit.h"
#include "AlienSoldier.h"
#include "../AlienDrone.h"
#include "../AlienMonster.h"
/*class AlienSoldier;
class AlienDrone;
class AlienMonster;
class ArmyUnit;
class Game;*/
#include "../Queue/Queue.h"
#include "../Queue/DoubleLinkedQueue.h"
#include "../Stack/Stack.h"

class AlienArmy
{
	Queue<AlienSoldier*> AS;
	DoubleLinkedQueue<AlienDrone*> AD;
	AlienMonster* AM[1000];
public:
	AlienArmy();
	bool Attack();
	bool AddUnit(Game* pG, ArmyUnit* AU); //pass parameters as an array.
	void PrintArmyInfo();
};

