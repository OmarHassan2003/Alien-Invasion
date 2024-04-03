#pragma once
#include "../ArmyUnit.h"
#include "AlienSoldier.h"
#include "../AlienDrone.h"
#include "../AlienMonster.h"
#include "../Queue/Queue.h"
#include "../Stack/Stack.h"
#include "../Queue/DoubleLinkedQueue.h"

class AlienArmy
{
	Queue<AlienSoldier*> AS;
	DoubleLinkedQueue<AlienDrone*> AD;
	AlienMonster* AM[1000];
public:
	AlienArmy();
	bool Attack();
	bool AddUnit();
	void PrintArmyInfo();
};

