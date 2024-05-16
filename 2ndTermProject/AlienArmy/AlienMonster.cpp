#include "AlienMonster.h"
#include "../Game.h"

AlienMonster::AlienMonster(Game* p, double HP, double pow, int ID_, int cap, int _Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, U)
{
}

bool AlienMonster::Attack()
{
	bool flag = false;
	Stack<EarthTank*> tempList1;
	Queue<EarthSoldier*> tempList2;
	Queue<SaverUnit*> tempList3;
	EarthTank* ET = nullptr;
	SaverUnit* SU = nullptr;
	int i;
	for (i = 0; i < GetAttackCap() / 2; i++)
	{
		if (pGame->Get_ET(ET))
		{
			if (ET->Get_Ta() == -1)
				ET->Set_Ta(pGame->Get_Tj());

			flag = true;
			double dmg = GetPower() * (GetHealth() / 100.0) / sqrt(ET->GetHealth());
			ET->SetHealth(ET->GetHealth() - dmg);
			tempList1.push(ET);
		}
		else break;
	}

	int remaining_AttackCapacity = GetAttackCap() - i;
	EarthSoldier* ES = nullptr;
	int j;
	for (j = 0; j < remaining_AttackCapacity / 2; j++)
	{
		if (pGame->Get_SU(SU))
		{
			flag = true;
			double dmg = GetPower() * (GetHealth() / 100.0) / sqrt(SU->GetHealth());
			SU->SetHealth(SU->GetHealth() - dmg);
			tempList3.enqueue(SU);
		}
		else break;
	}
	for (; j <= remaining_AttackCapacity; j++)
	{
		if (pGame->WillInfect())
		{
			if (pGame->Get_ES(ES))
			{
				flag = true;
				if (ES->getInfected() || ES->getImmune())
				{
					double dmg = GetPower() * (GetHealth() / 100.0) / sqrt(ES->GetHealth());
					ES->SetHealth(ES->GetHealth() - dmg);
					tempList2.enqueue(ES);
				}
				else
				{
					if (!ES->getImmune())
					{
						pGame->IncInfectedES();
						ES->setInfected(true);
						tempList2.enqueue(ES);
					}
				}
			}
			else
				break;
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
		else
			break;
	}

	if (pGame->Get_GameMode())
	{
		if (!tempList1.isEmpty() || !tempList2.isEmpty() || !tempList3.isEmpty())
		{
			cout << "AM " << this << " shots ";
			tempList1.print();
			cout << " ";
			tempList2.print();
			cout << " ";
			tempList3.print();
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
	while (!tempList3.isEmpty())
	{
		SaverUnit* temp = nullptr;
		tempList3.dequeue(temp);
		if (temp->GetHealth() <= 0)
			pGame->AddInKilledList(temp);
		else
			pGame->Add_SU(temp);
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
