#include "AlienMonster.h"
#include "../Game.h"

AlienMonster::AlienMonster(Game* p, int HP, int pow, int ID_, int cap, int _Tj)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj)
{
}

void AlienMonster::AddEarthUnitToList(EarthArmy* passed_EA)
{}

void AlienMonster::AddAlienUnitToList(AlienArmy* passed_AA)
{
	passed_AA->AddInAmArray(this);
}

bool AlienMonster::Attack()
{
	Stack<EarthTank*> tempList1;
	Queue<EarthSoldier*> tempList2;
	EarthTank* ET = nullptr;
	int i;
	for (i = 0; i < GetAttackCap() / 2 && pGame->Get_ET(ET); i++)
	{
		int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(ET->GetHealth()));
		ET->SetHealth(ET->GetHealth() - dmg);

		if (ET->GetHealth() <= 0)
			pGame->AddInKilledList(ET);
		else if (ET->GetHealth() < 0.2 * ET->GetInitialH())
			pGame->AddToUML(ET, -1);
		else
			tempList1.push(ET);
	}
	int remaining_AttackCapacity = GetAttackCap() - i;
	for (int i = 1; i <= remaining_AttackCapacity; i++)
	{
		EarthSoldier* ES = nullptr;
		if (pGame->Get_ES(ES))
		{
			int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(ES->GetHealth()));
			ES->SetHealth(ES->GetHealth() - dmg);

			if (ES->GetHealth() <= 0)
				pGame->AddInKilledList(ES);
			else if (ES->GetHealth() < 0.2 * ES->GetInitialH())
				pGame->AddToUML(ES, ES->GetInitialH() - ES->GetHealth());
			else
				tempList2.enqueue(ES);
		}
	}
	while (!tempList1.isEmpty())
	{
		EarthTank* temp = nullptr;
		tempList1.pop(temp);
		pGame->Add_ET(temp);
	}
	while (!tempList2.isEmpty())
	{
		EarthSoldier* temp = nullptr;
		tempList2.dequeue(temp);
		pGame->Add_ES(temp);
	}
	return true;
}

ostream& operator<<(ostream& COUT, AlienMonster* PAssed_AM)
{
	if (PAssed_AM)
	{
		COUT << PAssed_AM->GetID() << " ";
		return COUT;
	}
}
