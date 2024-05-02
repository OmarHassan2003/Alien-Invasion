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
			int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(pET->GetHealth()));
			pET->SetHealth(pET->GetHealth() - dmg);
			if (pET->GetHealth() <= 0)
				pGame->AddInKilledList(pET);
			else if (pET->GetHealth() < 0.2 * pET->GetInitialH())
				pGame->AddToETUML(pET);
			else
				temp_ET_Queue.enqueue(pET);
		}
	}
	EarthTank* tempET;
	while (!temp_ET_Queue.isEmpty())
	{
		temp_ET_Queue.dequeue(tempET);
		pGame->Add_ET(tempET);
	}
	Attack_Cap = GetAttackCap() - Attack_Cap;
	for (unsigned short i = 0;i < Attack_Cap;i++)
	{
		flag = true;
		if (pGame->Get_EG(pEG))
		{
			int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(pEG->GetHealth()));
			pEG->SetHealth(pEG->GetHealth() - dmg);
			if (pEG->GetHealth() <= 0)
				pGame->AddInKilledList(pEG);
			else
				temp_EG_Queue.enqueue(pEG);
		}
	}
	EarthGunnery* tempEG;
	while (!temp_EG_Queue.isEmpty())
	{
		temp_EG_Queue.dequeue(tempEG);
		pGame->Add_EG(tempEG);
	}
	return false;
}

ostream& operator<<(ostream& COUT, AlienDrone* PAssed_AD)
{
	COUT << PAssed_AD->GetID() << " ";
	return COUT;
}
