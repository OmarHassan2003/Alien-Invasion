#include "AlienArmy.h"
#include "../RandomGenerator/RandomGenerator.h"
AlienArmy::AlienArmy()
{
	for (int i = 0; i < 1000; i++)
		AM[i] = NULL;
}

bool AlienArmy::Attack()
{
	return false;
}

/*
bool AlienArmy::AddUnit(Game* pG, ArmyUnit* AU)
{
	if (AU->GetUnitType()==ArmyUnit::AS)
	{
		AS.enqueue(dynamic_cast<AlienSoldier*>(AU));
		return true;
	}
	if (AU->GetUnitType() == ArmyUnit::AM)
	{
		//Add monster
		return true;
	}
	if (AU->GetUnitType() == ArmyUnit::AD)
	{
		AD.enqueue(dynamic_cast<AlienDrone*>(AU));
		return true;
	}
	return false;
}
*/

bool AlienArmy::AddUnit(ArmyUnit* passed_AU)
{
	passed_AU->AddAlienUnitToList(this);
	return true;
}

void AlienArmy::PrintArmyInfo()
{
	AS_Queue.print();
	//AD_DQueue.print();
}

AlienSoldier* AlienArmy::pick_AS()
{
	AlienSoldier* tempPtr;
	if (AS_Queue.peek(tempPtr))
		return tempPtr;
	else return NULL;
}

AlienMonster* AlienArmy::pick_AM()
{
	AlienMonster* tempPtr;
	tempPtr = randAM();
	if(tempPtr)
		return tempPtr;
}

AlienDrone* AlienArmy::pick_AD(int x)
{
	AlienDrone* temp;
	if (x % 2 == 0)
		AD_DQueue.dequeue(temp);
	else AD_DQueue.GetRear(temp);
	return temp;
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
	AM[AM_Count++] = passed_AM;
}

void AlienArmy::AddInQueue(AlienSoldier* passed_AU)
{
	AS_Queue.enqueue(passed_AU);
}

void AlienArmy::AddInDoubleLinkedQueueQueue(AlienDrone* passed_AU)
{
	AD_DQueue.enqueue(passed_AU);
}

void AlienArmy::AddInAmArray(AlienMonster* passed_AU)
{
	AM[AM_Count++] = passed_AU;
}

//int AlienArmy::AM_Count()
//{
//	int count = 0;
//	int i = 0;
//	while (AM != NULL)
//		count++;
//	return count;
//}

AlienMonster* AlienArmy::randAM()
{
	RandomGenerator* randdo = new RandomGenerator();
	int y = randdo->RandGen(0, AM_Count);
	AlienMonster* temp = AM[y];
	AM[y] = AM[AM_Count];
	AM[AM_Count] = NULL;
	AM_Count--;
	return temp;
}

//int AlienArmy::RETAMCOUNT()
//{
//	return AM_Count;
//}
