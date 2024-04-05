#pragma once
#include "Queue/Queue.h"
#include "priQueue.h"
#include "Stack/Stack.h"
#include "Queue/DoubleLinkedQueue.h"

#include "ArmyUnit.h"

/*
#include "EarthArmy/EarthSoldier.h"
#include "EarthTank.h"
#include "EarthGunnery.h"

#include "AlienArmy/AlienSoldier.h"
#include "AlienMonster.h"
#include "AlienDrone.h"
*/

//#include "EarthArmy/EarthArmy.h"
//#include "AlienArmy/AlienArmy.h"



class Army
{

public:
	Army();
	virtual bool Attack() = 0;
	virtual bool AddUnit(ArmyUnit* passed_AU) = 0;
	virtual void PrintArmyInfo() = 0;
};

