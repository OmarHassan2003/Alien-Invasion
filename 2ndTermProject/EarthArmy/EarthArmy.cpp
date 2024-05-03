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
	if (HU_Stack.pop(HU)) //pop because it attacks one time then die
		HU->Attack();
	return true;
}

void EarthArmy::PrintArmyInfo()
{
	/*cout << Total_E_Units << "Total :";
	cout << ES_Queue.GetCount() << " ES /";
	cout << ET_Stack.GetCount() << " ET /";
	cout << EG_priQ.GetCount() << " EG /";
	cout << HU_Stack.GetCount() << " HU\n";*/
	cout << Total_E_Units << "Total :" << endl;
	cout << ES_Queue.GetCount() << " ES [";
	ES_Queue.print();
	cout << "]" << endl << ET_Stack.GetCount() << " ET [";
	ET_Stack.print();
	cout << "]" << endl << EG_priQ.GetCount() << " EG [";
	EG_priQ.print();
	cout << "]" << endl << HU_Stack.GetCount() << " EH [";
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

int EarthArmy::ES_Count() const
{
	return ES_Queue.GetCount();
}

int EarthArmy::ET_Count() const
{
	return ET_Stack.GetCount();
}

int EarthArmy::EG_Count() const
{
	return EG_priQ.GetCount();
}

int EarthArmy::EH_Count() const
{
	return HU_Stack.GetCount();
}

bool EarthArmy::AddUnit(ArmyUnit* passed_AU)
{
	Total_E_Units++;
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
	return ES_Queue.isEmpty() && EG_priQ.isEmpty() && ET_Stack.isEmpty() && HU_Stack.isEmpty();
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