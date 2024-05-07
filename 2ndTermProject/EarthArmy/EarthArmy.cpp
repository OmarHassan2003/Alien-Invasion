#include "EarthArmy.h"

#include "EarthSoldier.h"
#include "EarthGunnery.h"
#include "EarthTank.h"
#include "../HealUnit.h"
EarthArmy::EarthArmy()
{
	Won = false;
}

bool EarthArmy::Attack()
{
	if (isCompromised())
		IsAttack = false;
	else
	{
		IsAttack = false;
		EarthSoldier* ES = nullptr;
		if (ES_Queue.peek(ES))
			IsAttack |= (ES->Attack());

		EarthTank* ET;
		if (ET_Stack.peek(ET))
			IsAttack |= (ET->Attack());

		EarthGunnery* EG;
		int x;
		if (EG_priQ.peek(EG, x))
			IsAttack |= (EG->Attack());

		HealUnit* HU;
		if (HU_Stack.pop(HU))   //pop because it heals one time then die
			if (!HU->Attack())  // if it doesnt heal return it back
				HU_Stack.push(HU);
	}
	return IsAttack;
}

void EarthArmy::PrintArmyInfo()
{
	/*cout << Total_E_Units << "Total :";
	cout << ES_Queue.GetCount() << " ES /";
	cout << ET_Stack.GetCount() << " ET /";
	cout << EG_priQ.GetCount() << " EG /";
	cout << HU_Stack.GetCount() << " HU\n";*/
	cout << "Total :" << Total_Gen_E_Units << endl;
	cout << "Total ES: " << Total_Gen_ES << " Alive: " << ES_Queue.GetCount() << " ES [";
	ES_Queue.print();
	cout << "]" << endl;
	cout << "Total ET: " << Total_Gen_ET << " Alive: " << ET_Stack.GetCount() << " ET [";
	ET_Stack.print();
	cout << "]" << endl;
	cout << "Total EG: " << Total_Gen_EG << " Alive: " << EG_priQ.GetCount() << " EG [";
	EG_priQ.print();
	cout << "]" << endl;
	cout << "Total EH: " << Total_Gen_EH << " Alive: " << HU_Stack.GetCount() << " EH [";
	HU_Stack.print();
	cout << "]" << endl;
}

void EarthArmy::SetWon(bool p)
{
	Won = p;
}

bool EarthArmy::GetWon() const
{
	return Won;
}

void EarthArmy::SetIsAttack(bool p)
{
	IsAttack = p;
}

bool EarthArmy::GetIsAttack() const
{
	return IsAttack;
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

int EarthArmy::Total_ES_Count() const
{
	return Total_Gen_ES;
}

int EarthArmy::Total_ET_Count() const
{
	return Total_Gen_ET;
}

int EarthArmy::Total_EG_Count() const
{
	return Total_Gen_EG;
}

int EarthArmy::Total_EH_Count() const
{
	return Total_Gen_EH;
}

int EarthArmy::Total_EarthUnits_Count() const
{
	return Total_Gen_E_Units;
}

/*
bool EarthArmy::AddUnit(ArmyUnit* passed_AU)
{
	Total_Gen_E_Units++;
	if(passed_AU)
	{
		passed_AU->AddEarthUnitToList(this);
		return true;
	}
	return false;
}
*/
bool EarthArmy::AddUnit(ArmyUnit* passed_AU)
{
	Total_Gen_E_Units++;
	if (passed_AU)
	{
		if (passed_AU->GetUnitType() == ArmyUnit::ES)
		{
			Total_Gen_ES++;
			AddInQueue((EarthSoldier*)passed_AU);
		}
		else if (passed_AU->GetUnitType() == ArmyUnit::ET)
		{
			Total_Gen_ET++;
			AddInStack((EarthTank*)passed_AU);
		}
		else if (passed_AU->GetUnitType() == ArmyUnit::EG)
		{
			Total_Gen_EG++;
			AddInPriQueue((EarthGunnery*)passed_AU);
		}
		else if (passed_AU->GetUnitType() == ArmyUnit::EH)
		{
			Total_Gen_EH++;
			AddInHUStack((HealUnit*)passed_AU);
		}
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