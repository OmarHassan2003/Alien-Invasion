#include "AlienArmy.h"

#include "AlienDrone.h"
#include "AlienMonster.h"
#include "AlienSoldier.h"

AlienArmy::AlienArmy()
{
	for (int i = 0; i < 1000; i++)
		AM[i] = NULL;
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
	cout << RETAMCOUNT() << " AM [";
	Print_AM_Array(); 
	cout << "]" << endl << AD_DQueue.GetCount() << " AD [";
	AD_DQueue.print();
	cout << "]";
	//cout << ES_Queue.GetCount() << " ES [";
	//ES_Queue.print();
	//cout << "]" << endl << ET_Stack.GetCount() << " ET [";
	//ET_Stack.print();
	//cout << "]" << endl << EG_priQ.GetCount() << " EG [";
	//EG_priQ.print();
	//cout << "]" << endl;
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

AlienDrone* AlienArmy::pick_Rear_AD(int x)
{
	AlienDrone* pAD;
	AD_DQueue.GetRear(pAD);
	return pAD;
}

AlienMonster* AlienArmy::pick_AM()
{
	AlienMonster* tempPtr;
	tempPtr = randAM();
	if (tempPtr)
		return tempPtr;
	else return NULL;
}

AlienDrone* AlienArmy::pick_AD(int x)
{
	AlienDrone* temp = NULL;
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
	AM[y] = AM[AM_Count - 1];
	AM[AM_Count - 1] = NULL;
	AM_Count--;
	return temp;
}

int AlienArmy::RETAMCOUNT()
{
	return AM_Count;
}

void AlienArmy::Print_AM_Array()
{
	if (!AM_Count)
	{
		cout << "NO ELEMENTS";
		return;
	}
	for (int i = 0; i < AM_Count; i++)
	{
		if (AM_Count)
		{
			if (i == AM_Count - 1) cout << AM[i];
			else cout << AM[i] << ",";
		}
	}
}

bool AlienArmy::isComromised()
{
	if (AS_Queue.isEmpty() && AD_DQueue.isEmpty())
		return true;
	else
		return false;
}
