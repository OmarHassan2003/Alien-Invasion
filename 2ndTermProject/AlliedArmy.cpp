#include "AlliedArmy.h"
#include "Game.h"

AlliedArmy::AlliedArmy()
{
	Total_Gen_SU = 0;
	Succesful_Attack = false;
}

bool AlliedArmy::Attack()
{
	SaverUnit* SU;
	if (!SU_Queue.isEmpty())
	{
		SU_Queue.peek(SU);
		Succesful_Attack = SU->Attack();
	}
	return Succesful_Attack;
}

void AlliedArmy::PrintArmyInfo()
{
	cout << SU_Queue.GetCount() << " SU ";
	SU_Queue.print();
	cout << endl;
}

void AlliedArmy::withdraw_SU(Game* pGame)
{
	SaverUnit* SU;
	while (!SU_Queue.isEmpty())
	{
		SU_Queue.dequeue(SU);
		delete SU;
		SU = nullptr;
	}
}

void AlliedArmy::AddInQueue(SaverUnit* passed_AU)
{
	SU_Queue.enqueue(passed_AU);
}

bool AlliedArmy::pick_SU(SaverUnit*& SU)
{
	return SU_Queue.dequeue(SU);
}

int AlliedArmy::SU_Count() const
{
	return SU_Queue.GetCount();
}

int AlliedArmy::Total_SU_Count() const
{
	return Total_Gen_SU;
}

bool AlliedArmy::AddUnit(ArmyUnit* passed_AU)
{
	if (passed_AU)
	{
		SU_Queue.enqueue((SaverUnit*)passed_AU);
		Total_Gen_SU++;
		return true;
	}
	else return false;
}

int AlliedArmy::dead_percent()
{
	return double(SU_Count()) / Total_Gen_SU;
}

AlliedArmy::~AlliedArmy()
{
	SaverUnit* SU;
	while (!SU_Queue.isEmpty())
	{
		SU_Queue.dequeue(SU);
		delete SU;
		SU = nullptr;
	}
}


