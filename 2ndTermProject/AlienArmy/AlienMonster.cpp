#include "AlienMonster.h"
#include "../Game.h"

AlienMonster::AlienMonster(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, U)
{
}

bool AlienMonster::Attack()
{
	bool flag = false;
	Stack<EarthTank*> tempList1;
	Queue<EarthSoldier*> tempList2;
	EarthTank* ET = nullptr;
	int i;
	for (i = 0; i < GetAttackCap() / 2 && pGame->Get_ET(ET); i++)
	{
		if (ET->Get_Ta() == -1)
			ET->Set_Ta(pGame->Get_Tj());

		flag = true;
		int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(ET->GetHealth()));
		ET->SetHealth(ET->GetHealth() - dmg);
		tempList1.push(ET);
	}

	int remaining_AttackCapacity = GetAttackCap() - i;
	EarthSoldier* ES = nullptr;
	for (int j = 1; j <= remaining_AttackCapacity; j++)
	{
		if (pGame->WillInfect())
		{
			if (pGame->Get_ES(ES))
			{
				flag = true;
				if (ES->getInfected() || ES->getImmune())
				{
					int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(ES->GetHealth()));
					ES->SetHealth(ES->GetHealth() - dmg);
					tempList2.enqueue(ES);
				}
				else
				{
					if (!ES->getImmune())
					{
						ES->setInfected(true);
						tempList2.enqueue(ES);
					}
				}
			}
		}
		else if (pGame->Get_ES(ES))
		{
			if (ES->Get_Ta() == -1)
				ES->Set_Ta(pGame->Get_Tj());

			flag = true;
			int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(ES->GetHealth()));
			ES->SetHealth(ES->GetHealth() - dmg);
			tempList2.enqueue(ES);
		}
	}

	if (pGame->Get_GameMode())
	{
		if (!tempList1.isEmpty() || !tempList2.isEmpty())
		{
			cout << "AM " << this << " shots ";
			tempList1.print();
			cout << " ";
			tempList2.print();
			cout << endl;
		}
	}

	while (!tempList1.isEmpty())
	{
		EarthTank* temp = nullptr;
		tempList1.pop(temp);
		if (temp->GetHealth() <= 0)
			pGame->AddInKilledList(temp);
		else if (temp->GetHealth() < 0.2 * temp->GetInitialH())
			pGame->AddToETUML(temp);
		else
			pGame->Add_ET(temp);
	}
	while (!tempList2.isEmpty())
	{
		EarthSoldier* temp = nullptr;
		tempList2.dequeue(temp);
		if (temp->GetHealth() <= 0)
			pGame->AddInKilledList(temp);
		else if (temp->GetHealth() < 0.2 * temp->GetInitialH())
			pGame->AddToESUML(temp);
		else
			pGame->Add_ES(temp);
	}
	return flag;
}

ostream& operator<<(ostream& COUT, AlienMonster* PAssed_AM)
{
	if (PAssed_AM)
	{
		COUT << PAssed_AM->GetID();
		return COUT;
	}
}
