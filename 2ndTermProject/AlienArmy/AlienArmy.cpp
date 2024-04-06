#include "AlienArmy.h"

AlienArmy::AlienArmy()
{
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

void AlienArmy::AddInQueue(ArmyUnit* passed_AU)
{
	AS_Queue.enqueue((AlienSoldier*)passed_AU);
}

void AlienArmy::AddInDoubleLinkedQueueQueue(ArmyUnit* passed_AU)
{
	AD_DQueue.enqueue((AlienDrone*)passed_AU);
}
