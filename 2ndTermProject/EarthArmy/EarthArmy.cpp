#include "EarthArmy.h"

EarthArmy::EarthArmy()
{
}

bool EarthArmy::AddUnit(Game* pG, ArmyUnit* AU)
{
	if (AU->GetUnitType()==ArmyUnit::ES)
	{
		ES.enqueue(dynamic_cast<EarthSoldier*>(AU));
		return true;
	}
	if (AU->GetUnitType() == ArmyUnit::ET)
	{
		ET.push(dynamic_cast<EarthTank*>(AU));
		return true;
	}
	if (AU->GetUnitType() == ArmyUnit::EG)
	{
		int pri = AU->GetHealth() + AU->GetPower();
		EG.enqueue(dynamic_cast<EarthGunnery*>(AU), pri);
		return true;
	}
	return false;
}

void EarthArmy::PrintArmyInfo()
{
	ES.print();
}
