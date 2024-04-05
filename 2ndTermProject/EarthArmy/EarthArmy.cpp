#include "EarthArmy.h"

EarthArmy::EarthArmy()
{
}

/*bool EarthArmy::AddUnit(Game* pG, ArmyUnit* AU)
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
}*/

void EarthArmy::AddInStack(EarthTank* passed_AU)
{
	ET_Stack.push(passed_AU);
}

void EarthArmy::AddInQueue(EarthSoldier* passed_AU)
{
	ES_Queue.enqueue(passed_AU);
}

void EarthArmy::AddInPriQueue(EarthGunnery* passed_AU)
{
	ArmyUnit* temp = (ArmyUnit*)passed_AU;
	EG_priQ.enqueue(passed_AU,temp->GetHealth() + temp->GetAttackCap());
}

bool EarthArmy::AddUnit(ArmyUnit* passed_AU)
{
	passed_AU->AddEarthUnitToList(this);
	return true;
}

void EarthArmy::PrintArmyInfo()
{
	EG_priQ.print();
	cout << "//////////////////////" << endl;
	ES_Queue.print();
	ET_Stack.print();
}
