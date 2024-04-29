#include "EarthTank.h"
#include "../Game.h"


EarthTank::EarthTank(Game* p, int HP, int pow, int ID_, int cap, int _Tj)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj)
{
}

void EarthTank::AddEarthUnitToList(EarthArmy* passed_EA)
{
	passed_EA->AddInStack(this);
}

void EarthTank::AddAlienUnitToList(AlienArmy* passed_AA)
{
}

bool EarthTank::Attack()
{
	double ES_COUNT = pGame->Get_ES_Count();
	double AS_COUNT = pGame->Get_AS_Count();
	Queue<AlienMonster*> tempList1;
	Queue<AlienSoldier*> tempList2;
	if (ES_COUNT < 0.3 * AS_COUNT)
	{
		int count = 0;
		AlienMonster* AM = nullptr;
		while (count < GetAttackCap() / 2 && pGame->Get_AM(AM));
		{
			int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(AM->GetHealth()));
			AM->SetHealth(AM->GetHealth() - dmg);
			count++;
			if (AM->GetHealth() <= 0)
				pGame->AddInKilledList(AM);
			else tempList1.enqueue(AM);
		}
		int remaining_AttackCapacity = GetAttackCap() - count;
		for (int i = 1; i <= remaining_AttackCapacity; i++)
		{
			AlienSoldier* AS = nullptr;
			if (pGame->Get_AS(AS))
			{
				int dmg = (GetPower() * (GetHealth() / 100)) / sqrt(AS->GetHealth());
			//	AS -= dmg;
				if (AS->GetHealth() <= 0)
					pGame->AddInKilledList(AS);
				else tempList2.enqueue(AS);
			}
		}
	}
	else
	{
		for (int i = 1; i <= GetAttackCap(); i++)
		{
			AlienMonster* AM = nullptr;
			if (pGame->Get_AM(AM))
			{
				int dmg = (GetPower() * (GetHealth() / 100)) / sqrt(AM->GetHealth());
	//			AM -= dmg;
				if (AM->GetHealth() <= 0)
					pGame->AddInKilledList(AM);
				else tempList1.enqueue(AM);
			}
		}
	}
	while (!tempList1.isEmpty())
	{
		AlienMonster* temp = nullptr;
		tempList1.dequeue(temp);
		pGame->Add_AM(temp);
	}
	while (!tempList2.isEmpty())
	{
		AlienSoldier* temp = nullptr;
		tempList2.dequeue(temp);
		pGame->Add_AS(temp);
	}
	return true;
}

ostream& operator<<(ostream& COUT, EarthTank* Passed_AU)
{
	COUT << Passed_AU->GetID() << " ";
	return COUT;
}
