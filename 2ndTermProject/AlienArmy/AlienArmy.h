#pragma once
#include "../ArmyUnit.h"
#include "AlienSoldier.h"
#include "../AlienDrone.h"
#include "../Queue/Queue.h"
#include "../Queue/DoubleLinkedQueue.h"
#include "../Stack/Stack.h"

class AlienArmy
{
	Queue<AlienSoldier*> AS;
	DoubleLinkedQueue<AlienDrone*> AD;
public:
	AlienArmy();
	bool Attack();
	bool AddUnit(char u, int, int, int, int, int); //pass parameters as an array.
	void PrintArmyInfo();
};

