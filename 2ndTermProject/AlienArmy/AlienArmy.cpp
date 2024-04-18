#include "AlienArmy.h"

#include "AlienDrone.h"
#include "AlienMonster.h"
#include "AlienSoldier.h"

AlienArmy::AlienArmy()
{
}

bool AlienArmy::Attack()
{
	return false;
}

bool AlienArmy::AddUnit(ArmyUnit* passed_AU)
{
	if (passed_AU)
	{
		passed_AU->AddAlienUnitToList(this);
		return true;
	}
	return false;
}

void AlienArmy::PrintArmyInfo()
{
	cout << AS_Queue.GetCount() << " AS [";
	AS_Queue.print();
	cout << "]" << endl;
	cout << AM.GetCount() << " AM [";
	AM.print(); 
	cout << "]" << endl << AD_DQueue.GetCount() << " AD [";
	AD_DQueue.print();
	cout << "]";
}

AlienSoldier* AlienArmy::pick_AS()
{
	AlienSoldier* tempPtr;
	if (AS_Queue.peek(tempPtr))
		return tempPtr;
	else return NULL;
}

AlienSoldier* AlienArmy::Remove_AS()
{
	AlienSoldier* tempPtr;
	if (AS_Queue.dequeue(tempPtr))
		return tempPtr;
	else return NULL;
}

AlienMonster* AlienArmy::pick_AM()
{
	AlienMonster* tempPtr;
	if (AM.Pick(tempPtr))
		return tempPtr;
	else return NULL;
}

AlienDrone* AlienArmy::pick_AD(AlienDrone*& passed_AD)
{
	AlienDrone* temp = NULL;
	AD_DQueue.GetRear(passed_AD);
	if (AD_DQueue.dequeue(temp))
		return temp;
	else return NULL;
}

void AlienArmy::InsertAS(AlienSoldier* passed_AS)
{
	AS_Queue.enqueue(passed_AS);
}

void AlienArmy::InsertAD(AlienDrone* passed_AD)
{
	AD_DQueue.enqueue(passed_AD);
}

void AlienArmy::InsertAM(AlienMonster* passed_AM)
{
	AM.Add(passed_AM);
}

void AlienArmy::AddInQueue(AlienSoldier* passed_AU) 
{
	if (passed_AU)
	{
		AS_Queue.enqueue(passed_AU);
	}
}

void AlienArmy::AddInDoubleLinkedQueueQueue(AlienDrone* passed_AU)
{
	AD_DQueue.enqueue(passed_AU);
}

void AlienArmy::AddInAmArray(AlienMonster* passed_AU)
{
	AM.Add(passed_AU);
}

