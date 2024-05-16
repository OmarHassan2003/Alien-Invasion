#include "AlienArmy.h"
#include "AlienDrone.h"
#include "AlienMonster.h"
#include "AlienSoldier.h"

AlienArmy::AlienArmy()
{
	Won = false;
}

bool AlienArmy::Attack()
{
	IsAttack = false;
	AlienSoldier* AS;
	if (AS_Queue.peek(AS))
		IsAttack |= AS->Attack();

	AlienMonster* ALM = nullptr;
	if (AM.Peek(ALM))
		IsAttack |= ALM->Attack();

	AlienDrone* AD1, * AD2;
	if (AD_DQueue.GetCount() > 1)
	{
		AD_DQueue.peek(AD1);
		AD_DQueue.peek_rear(AD2);
		IsAttack |= AD1->Attack();
		IsAttack |= AD2->Attack();
	}
	return IsAttack;
}

void AlienArmy::PrintArmyInfo()
{
	cout << AS_Queue.GetCount() << " AS ";
	AS_Queue.print();
	cout << endl;

	cout << AM.GetCount() << " AM ";
	AM.print();
	cout << endl;

	cout << AD_DQueue.GetCount() << " AD ";
	AD_DQueue.print();
	cout << endl;
}

void AlienArmy::SetWon(bool p)
{
	Won = p;
}

bool AlienArmy::GetWon() const
{
	return Won;
}

void AlienArmy::SetIsAttack(bool p)
{
	IsAttack = p;
}

bool AlienArmy::GetIsAttack() const
{
	return IsAttack;
}

bool AlienArmy::pick_AS(AlienSoldier*& EPtr)
{
	return AS_Queue.dequeue(EPtr);
}

bool AlienArmy::pick_AM(AlienMonster*& passed_AM)
{
	return AM.Pick(passed_AM);
}

bool AlienArmy::pick_Rear_AD(AlienDrone*& passed_AD)
{
	return AD_DQueue.GetRear(passed_AD);
}

bool AlienArmy::peek_AD(AlienDrone*& passed_AD)
{
	return AD_DQueue.peek(passed_AD);
}

bool AlienArmy::peek_AD_Rear(AlienDrone*& passed_AD)
{
	return AD_DQueue.peek_rear(passed_AD);
}

bool AlienArmy::peek_AM(AlienMonster*& passed_AM)
{
	return AM.Peek(passed_AM);
}

int AlienArmy::AS_Count() const
{
	return AS_Queue.GetCount();
}

int AlienArmy::AD_Count() const
{
	return AD_DQueue.GetCount();
}

int AlienArmy::AM_Count() const
{
	return AM.GetCount();
}

int AlienArmy::Total_AS_Count() const
{
	return Total_Gen_AS;
}

int AlienArmy::Total_AM_Count() const
{
	return Total_Gen_AM;
}

int AlienArmy::Total_AD_Count() const
{
	return Total_Gen_AD;
}

int AlienArmy::Total_AlienUnits_Count() const
{
	return Total_Gen_A_Units;
}

bool AlienArmy::pick_AD(AlienDrone*& passed_AD) //change to bool
{
	return AD_DQueue.dequeue(passed_AD);
}

bool AlienArmy::AddUnit(ArmyUnit* passed_AU)
{
	Total_Gen_A_Units++;
	if (passed_AU)
	{
		if (passed_AU->GetUnitType() == ArmyUnit::AS)
		{
			Total_Gen_AS++;
			AddInQueue((AlienSoldier*)passed_AU);
		}
		else if (passed_AU->GetUnitType() == ArmyUnit::AM)
		{
			Total_Gen_AM++;
			AddInAmArray((AlienMonster*)passed_AU);
		}
		else if (passed_AU->GetUnitType() == ArmyUnit::AD)
		{
			Total_Gen_AD++;
			AddInDoubleLinkedQueueQueue((AlienDrone*)passed_AU);
		}
		return true;
	}
	return false;
}

void AlienArmy::AddInQueue(AlienSoldier* passed_AU) 
{
	AS_Queue.enqueue(passed_AU);
}

void AlienArmy::AddInAmArray(AlienMonster* passed_AU)
{
	AM.Add(passed_AU);
}

void AlienArmy::AddInDoubleLinkedQueueQueue(AlienDrone* passed_AU)
{
	AD_DQueue.enqueue(passed_AU);
}

void AlienArmy::AddInLinkedQueue_Front(AlienDrone* passed_AU)
{
	AD_DQueue.addToFront(passed_AU);
}

bool AlienArmy::isCompromised()
{	
	return AS_Queue.isEmpty() && AD_DQueue.isEmpty() && AM.isEmpty();
}

AlienArmy::~AlienArmy()
{
	AlienSoldier* dels;
	while (!AS_Queue.isEmpty())
	{
		AS_Queue.dequeue(dels);
		delete dels;
		dels = nullptr;
	}

	AlienMonster* delm;
	while (!AM.isEmpty())
	{
		AM.Pick(delm);
		delete delm;
		delm = nullptr;
	}

	AlienDrone* deld;
	while (!AD_DQueue.isEmpty())
	{
		AD_DQueue.dequeue(deld);
		delete deld;
		deld = nullptr;
	}
}