#pragma once
#include "Queue/Queue.h"
#include "Queue/priQueue.h"
#include "Stack/Stack.h"
#include "Queue/DoubleLinkedQueue.h"
#include "DynamicArray.h"
#include "ArmyUnit.h"


class Army
{

public:
	Army();
	virtual bool Attack() = 0;
	virtual bool AddUnit(ArmyUnit* passed_AU) = 0;
	virtual void PrintArmyInfo() = 0;
};

