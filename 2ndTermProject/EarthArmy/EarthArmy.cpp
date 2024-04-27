#include "EarthArmy.h"

#include "EarthSoldier.h"
#include "EarthGunnery.h"
#include "EarthTank.h"
#include "../HealUnit.h"
EarthArmy::EarthArmy()
{
	
}

bool EarthArmy::Attack()
{
	EarthSoldier* ES = nullptr;
	if (ES_Queue.peek(ES))
		ES->Attack();

	EarthGunnery* EG;
	int x;
	if (EG_priQ.peek(EG, x))
		EG->Attack();

	EarthTank* ET;
	if (ET_Stack.peek(ET))
		ET->Attack();

	HealUnit* HU;
	if (HU_Stack.peek(HU))
		HU->Attack();
	 // How to move the HU to the killedlist in the GAME class?
	return true;
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
	return ES_Queue.dequeue(EPtr);
}

bool EarthArmy::pick_ET(EarthTank*& Eptr)
{
	return ET_Stack.pop(Eptr);
}

bool EarthArmy::pick_EG(EarthGunnery*& EPtr)
{
	int x = 0;
	return EG_priQ.dequeue(EPtr, x);
}

bool EarthArmy::pick_HU(HealUnit*& Eptr)
{
	return HU_Stack.pop(Eptr);
}

bool EarthArmy::peek_EG(EarthGunnery*& EPtr)
{
	int x;
	return EG_priQ.peek(EPtr,x);
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

void EarthArmy::AddInQueue(EarthSoldier* passed_AU)
{
		ES_Queue.enqueue(passed_AU);
}

void EarthArmy::AddInStack(EarthTank* passed_AU)
{
	ET_Stack.push(passed_AU);
}

void EarthArmy::AddInPriQueue(EarthGunnery* passed_AU)
{
	ArmyUnit* temp = (ArmyUnit*)passed_AU;
	EG_priQ.enqueue(passed_AU,temp->GetHealth() + temp->GetPower());
}

void EarthArmy::AddInHUStack(HealUnit* passed_HU)
{
	HU_Stack.push(passed_HU);
}

bool EarthArmy::isCompromised()
{
	return ES_Queue.isEmpty() && EG_priQ.isEmpty() && ET_Stack.isEmpty();
}

EarthArmy::~EarthArmy()
{
	EarthSoldier* dels;
	while (!ES_Queue.isEmpty())
	{
		ES_Queue.dequeue(dels);
		delete dels;
		dels = nullptr;
	}
	
	EarthTank* delt;
	while (!ET_Stack.isEmpty())
	{
		ET_Stack.pop(delt);
		delete delt;
		delt = nullptr;
	}
	
	EarthGunnery* delg;
	int x = 0;
	while (!EG_priQ.isEmpty())
	{
		EG_priQ.dequeue(delg, x);
		delete delg;
		delg = nullptr;
	}
}