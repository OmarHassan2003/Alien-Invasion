#include "AlienDrone.h"
#include "../Game.h"

AlienDrone::AlienDrone(Game* p, int HP, int pow, int ID_, int cap, int Tj, Unit U):
	ArmyUnit(p, HP, pow, ID_, cap, Tj, U)
{
}

void AlienDrone::AddEarthUnitToList(EarthArmy* passed_EA)
{
}

void AlienDrone::AddAlienUnitToList(AlienArmy* passed_AA)
{
	passed_AA->AddInDoubleLinkedQueueQueue(this);
}

bool AlienDrone::Attack()
{
	bool flag = false;
	EarthTank* pET;
	EarthGunnery* pEG;
	Queue<EarthTank*> temp_ET_Queue;
	Queue<EarthGunnery*> temp_EG_Queue;
	unsigned short Attack_Cap = GetAttackCap() / 2;
	for (unsigned short i = 0;i < Attack_Cap;i++)
	{
		flag = true;
		if (pGame->Get_ET(pET))
		{
			if (pET->Get_Ta() == -1)
				pET->Set_Ta(pGame->Get_Tj());

			int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(pET->GetHealth()));
			pET->SetHealth(pET->GetHealth() - dmg);
		
				temp_ET_Queue.enqueue(pET);
		}
	}
	Attack_Cap = GetAttackCap() - Attack_Cap;
	for (unsigned short i = 0;i < Attack_Cap;i++)
	{
		flag = true;
		if (pGame->Get_EG(pEG))
		{
			if (pEG->Get_Ta() == -1)
				pEG->Set_Ta(pGame->Get_Tj());

			int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(pEG->GetHealth()));
			pEG->SetHealth(pEG->GetHealth() - dmg);
			temp_EG_Queue.enqueue(pEG);
		}
	}

	if (pGame->Get_GameMode())
	{
		if (!temp_ET_Queue.isEmpty() || !temp_EG_Queue.isEmpty())
		{
			cout << "AD " << this << "shots [";
			if (!temp_ET_Queue.isEmpty())
			{
				temp_ET_Queue.print();
			}
			if (temp_ET_Queue.isEmpty())
				cout << "";
			else cout << "] [";
			if (!temp_EG_Queue.isEmpty())
			{
				temp_EG_Queue.print();
			}
			cout << "]";
			cout << endl;
		}
	}

	EarthTank* tempET;
	while (!temp_ET_Queue.isEmpty())
	{
		temp_ET_Queue.dequeue(tempET);
		if (tempET->GetHealth() <= 0)
			pGame->AddInKilledList(tempET);
		else if (tempET->GetHealth() < 0.2 * tempET->GetInitialH())
			pGame->AddToETUML(tempET);
		else
			pGame->Add_ET(tempET);
	}
	EarthGunnery* tempEG;
	while (!temp_EG_Queue.isEmpty())
	{
		temp_EG_Queue.dequeue(tempEG);
		if (tempEG->GetHealth() <= 0)
			pGame->AddInKilledList(tempEG);
		else
			pGame->Add_EG(tempEG);
	}
	return false;
}

ostream& operator<<(ostream& COUT, AlienDrone* PAssed_AD)
{
	COUT << PAssed_AD->GetID() << " ";
	return COUT;
}
