#include "EarthArmy.h"
#include "EarthSoldier.h"
#include "EarthGunnery.h"
#include "EarthTank.h"
#include "../HealUnit.h"
#include "../RandomGenerator/RandomGenerator.h"

EarthArmy::EarthArmy()
{
	Won = false;
}

void EarthArmy::SetRandGen(RandomGenerator* p)
{
	randgen = p;
}

void EarthArmy::IncInfectedES()
{
	Total_Infected++;
}

int EarthArmy::GetTotal_Infected()
{
	return Total_Infected;
}

bool EarthArmy::Attack()
{
	SpreadInfection();
	IsAttack = false;
	EarthSoldier* ES = nullptr;
	if (ES_Queue.peek(ES))
	{
		if (ES->getInfected())
		{
			ES_Queue.dequeue(ES);
			ES_Queue.enqueue(ES);
		}
		IsAttack |= (ES->Attack());
	}
	EarthTank* ET;
	if (ET_Stack.peek(ET))
		IsAttack |= (ET->Attack());

	EarthGunnery* EG;
	int x;
	if (EG_priQ.peek(EG, x))
		IsAttack |= (EG->Attack());

	HealUnit* HU;
	if (HU_Stack.pop(HU))   //pop because it heals one time then die
	{
		if (!HU->Attack())  // if it doesn't heal return it back
			HU_Stack.push(HU);
		Total_Healed += HU->GetHealedCount();
	}
	return IsAttack;
}

void EarthArmy::PrintArmyInfo()
{
	cout << ES_Queue.GetCount() << " ES ";
	ES_Queue.print();
	cout << endl;

	cout << ET_Stack.GetCount() << " ET ";
	ET_Stack.print();
	cout << endl;

	cout << EG_priQ.GetCount() << " EG ";
	EG_priQ.print();
	cout << endl;

	cout << HU_Stack.GetCount() << " EH ";
	HU_Stack.print();
	cout << endl;
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

int EarthArmy::ES_Infected_Count()
{
	int Counter = 0;
	EarthSoldier* Temp_ES;
	Stack<EarthSoldier*> Temp_Stack;
	while (!ES_Queue.isEmpty())
	{
		ES_Queue.dequeue(Temp_ES);
		if (Temp_ES->getInfected())
			Counter++;
		Temp_Stack.push(Temp_ES);
	}
	while (!Temp_Stack.isEmpty())
	{
		Temp_Stack.pop(Temp_ES);
		ES_Queue.enqueue(Temp_ES);
	}
	return Counter;
}

void EarthArmy::SpreadInfection()
{
	Queue<EarthSoldier*>TempES_Queue_Ultra;
	Queue<EarthSoldier*>TempES_Queue;
	bool IsThereInfectedSoldiers = false;
	EarthSoldier* tempES_Ptr = nullptr;
	EarthSoldier* tempES_Infected_Ptr = nullptr;
	unsigned short random_value;
	const unsigned short ES_Num = ES_Count();
	while (!ES_Queue.isEmpty())
	{
		ES_Queue.dequeue(tempES_Ptr);
		TempES_Queue_Ultra.enqueue(tempES_Ptr);
		TempES_Queue.enqueue(tempES_Ptr);
		if (tempES_Ptr->getInfected())
			IsThereInfectedSoldiers = true;
	}
	if (IsThereInfectedSoldiers)
	{
		if (randgen->RandGen(0, 100) <= 2)
		{
			Queue<EarthSoldier*> ES_Temp;
			random_value = randgen->RandGen(1, ES_Num);
			for (unsigned short i = 0;i < random_value - 1;i++)
			{
				TempES_Queue.dequeue(tempES_Ptr);
				ES_Temp.enqueue(tempES_Ptr);
			}
			TempES_Queue.dequeue(tempES_Ptr);
			if (!tempES_Ptr->getImmune())
			{
				tempES_Ptr->setInfected(true);
				IncInfectedES();
			}
			ES_Temp.enqueue(tempES_Ptr);
			for (unsigned short i = random_value;i < ES_Num;i++)
			{
				TempES_Queue.dequeue(tempES_Ptr);
				ES_Temp.enqueue(tempES_Ptr);
			}
			while (!ES_Temp.isEmpty())
			{
				ES_Temp.dequeue(tempES_Ptr);
				TempES_Queue.enqueue(tempES_Ptr);
			}
		}
	}
	while (!TempES_Queue_Ultra.isEmpty())
	{
		TempES_Queue_Ultra.dequeue(tempES_Ptr);
		ES_Queue.enqueue(tempES_Ptr);
	}
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

int EarthArmy::Total_HealedCount() const
{
	return Total_Healed;
}

int EarthArmy::Total_EarthUnits_Count() const
{
	return Total_Gen_E_Units;
}

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

