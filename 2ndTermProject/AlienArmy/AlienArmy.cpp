#include "AlienArmy.h"

AlienArmy::AlienArmy()
{
	for (int i = 0; i < 1000; i++)
		AM[i] = NULL;
}

bool AlienArmy::Attack()
{
	return false;
}

/*
bool AlienArmy::AddUnit(Game* pG, ArmyUnit* AU)
{
	if (AU->GetUnitType()==ArmyUnit::AS)
	{
		AS.enqueue(dynamic_cast<AlienSoldier*>(AU));
		return true;
	}
	if (AU->GetUnitType() == ArmyUnit::AM)
	{
		//Add monster
		return true;
	}
	if (AU->GetUnitType() == ArmyUnit::AD)
	{
		AD.enqueue(dynamic_cast<AlienDrone*>(AU));
		return true;
	}
	return false;
}
*/

bool AlienArmy::AddUnit(ArmyUnit* passed_AU)
{
	passed_AU->AddAlienUnitToList(this);
	return true;
}

void AlienArmy::PrintArmyInfo()
{
	AS_Queue.print();
	AD_DQueue.print();
}

void AlienArmy::AddInQueue(AlienSoldier* passed_AU)
{
	AS_Queue.enqueue(passed_AU);
}

void AlienArmy::AddInDoubleLinkedQueueQueue(AlienDrone* passed_AU)
{
	AD_DQueue.enqueue(passed_AU);
}

void AlienArmy::AddInAmArray(AlienMonster* passed_AU)
{
	static int x = 0;
	AM[x++] = passed_AU;
}
