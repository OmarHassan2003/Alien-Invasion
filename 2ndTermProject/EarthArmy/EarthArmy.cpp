#include "EarthArmy.h"

EarthArmy::EarthArmy()
{
}

bool EarthArmy::Attack()
{
	return false;
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
	EG_priQ.enqueue(passed_AU,temp->GetHealth() + temp->GetPower());
}

bool EarthArmy::AddUnit(ArmyUnit* passed_AU)
{
	passed_AU->AddEarthUnitToList(this);
	return true;
}

void EarthArmy::PrintArmyInfo()
{
	//EG_priQ.print();
	ES_Queue.print();
	//ET_Stack.print();
}

EarthSoldier* EarthArmy::pick_ES()
{
	EarthSoldier* temp_ptr;
	ES_Queue.dequeue(temp_ptr);
	return temp_ptr;
}

EarthGunnery* EarthArmy::pick_EG()
{
	EarthGunnery* temp_ptr;
	int x = 0;
	if (EG_priQ.dequeue(temp_ptr, x))
		return temp_ptr;
	else
		return NULL;
}

EarthTank* EarthArmy::pick_ET()
{
	EarthTank* temp_ptr;
	ET_Stack.pop(temp_ptr);
	return temp_ptr;
}

void EarthArmy::InsertES(EarthSoldier* passed_ES)
{
	ES_Queue.enqueue(passed_ES);
}

void EarthArmy::InsertEG(EarthGunnery* passed_EG)
{
	if (passed_EG)
	{
		ArmyUnit* temp = (ArmyUnit*)passed_EG;
		EG_priQ.enqueue(passed_EG, temp->GetHealth() + temp->GetPower());
	}
}

void EarthArmy::InsertET(EarthTank* passed_ET)
{
	ET_Stack.push(passed_ET);
}
