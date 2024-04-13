#include "EarthArmy.h"

#include "EarthSoldier.h"
#include "EarthGunnery.h"
#include "EarthTank.h"

EarthArmy::EarthArmy()
{
	
}

bool EarthArmy::Attack()
{
	return false;
}

void EarthArmy::AddInStack(EarthTank* passed_AU)
{
	ET_Stack.push(passed_AU);
}

void EarthArmy::AddInQueue(EarthSoldier* passed_AU)
{
	if(passed_AU)
	{
		ES_Queue.enqueue(passed_AU);
	}
}

void EarthArmy::AddInPriQueue(EarthGunnery* passed_AU)
{
	ArmyUnit* temp = (ArmyUnit*)passed_AU;
	EG_priQ.enqueue(passed_AU,temp->GetHealth() + temp->GetPower());
}

bool EarthArmy::AddUnit(ArmyUnit* passed_AU)
{
	if(passed_AU)
	{
		passed_AU->AddEarthUnitToList(this);
		return true;
	}
	return false;
}

void EarthArmy::PrintArmyInfo()
{
	cout << ES_Queue.GetCount() << " ES [";
	ES_Queue.print();
	cout << "]" << endl << ET_Stack.GetCount() << " ET [";
	ET_Stack.print();
	cout << "]" << endl << EG_priQ.GetCount() << " EG [";
	EG_priQ.print();
	cout << "]";
}

bool EarthArmy::pick_ES(EarthSoldier*& EPtr)
{
	if (ES_Queue.dequeue(EPtr))
		return true;
	else
		return false;
}

bool EarthArmy::pick_EG(EarthGunnery*& EPtr)
{
	int x = 0;
	if (EG_priQ.dequeue(EPtr, x))
		return true;
	else
		return false;
}

bool EarthArmy::pick_ET(EarthTank*& Eptr)
{
	if (ET_Stack.pop(Eptr))
		return true;
	else
		return false;
}

void EarthArmy::InsertES(EarthSoldier* passed_ES)
{
	if(passed_ES)
	{
		ES_Queue.enqueue(passed_ES);
	}
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
