#include "EarthTank.h"
#include "../Game.h"


EarthTank::EarthTank(Game* p, double HP, double pow, int ID_, int cap, int _Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, U)
{
}

bool EarthTank::Attack()
{
	bool flag = false;
	double ES_COUNT = pGame->Get_Count(ES);
	double AS_COUNT = pGame->Get_Count(AS);
	Queue<AlienMonster*> tempList1;
	Queue<AlienSoldier*> tempList2;

	if (ES_COUNT < 0.3 * AS_COUNT)
	{
		int count = 0;
		AlienMonster* AM = nullptr;
		while (count < GetAttackCap() / 2)
		{
			if (pGame->Get_AM(AM))
			{
				flag = true;
				if (AM->Get_Ta() == -1)
					AM->Set_Ta(pGame->Get_Tj());

				double dmg = GetPower() * (GetHealth() / 100.0) / sqrt(AM->GetHealth());
				AM->SetHealth(AM->GetHealth() - dmg);
				tempList1.enqueue(AM);
			}
			else
				break;
			count++;
		}

		int remaining_AttackCapacity = GetAttackCap() - count;
		for (int i = 1; i <= remaining_AttackCapacity; i++)
		{
			AlienSoldier* AS = nullptr;
			if (pGame->Get_AS(AS))
			{
				flag = true;
				if (AS->Get_Ta() == -1)
					AS->Set_Ta(pGame->Get_Tj());

				double dmg = GetPower() * (GetHealth() / 100.0) / sqrt(AS->GetHealth());
				AS->SetHealth(AS->GetHealth() - dmg);
				tempList2.enqueue(AS);
			}
			else
				break;
		}
	}

	else
	{
		for (int i = 1; i <= GetAttackCap(); i++)
		{
			AlienMonster* AM = nullptr;
			if (pGame->Get_AM(AM))
			{
				flag = true;
				if (AM->Get_Ta() == -1)
					AM->Set_Ta(pGame->Get_Tj());

				double dmg = (GetPower() * (GetHealth() / 100.0)) / sqrt(AM->GetHealth());
				AM->SetHealth(AM->GetHealth() - dmg);
				tempList1.enqueue(AM);
			}
			else
				break;
		}
	}

	if (pGame->Get_GameMode())
	{
		if (!tempList1.isEmpty() || !tempList2.isEmpty())
		{
			cout << "ET " << this << " shots ";
			tempList1.print();
			cout << " ";
			tempList2.print();
			cout << endl;
		}
	}

	while (!tempList1.isEmpty())
	{
		AlienMonster* temp = nullptr;
		tempList1.dequeue(temp);
		if (temp->GetHealth() <= 0)
			pGame->AddInKilledList(temp);
		else
			pGame->Add_AM(temp);
	}

	while (!tempList2.isEmpty())
	{
		AlienSoldier* temp = nullptr;
		tempList2.dequeue(temp);
		if (temp->GetHealth() <= 0)
			pGame->AddInKilledList(temp);
		else
			pGame->Add_AS(temp);
	}

	return flag;

}

ostream& operator<<(ostream& COUT, EarthTank* Passed_AU)
{
	COUT << Passed_AU->GetID();
	return COUT;
}
