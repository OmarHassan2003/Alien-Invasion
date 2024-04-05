#include "AlienArmy.h"

AlienArmy::AlienArmy()
{
}

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
