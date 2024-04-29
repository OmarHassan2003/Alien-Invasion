#include "AlienDrone.h"
#include "../Game.h"

AlienDrone::AlienDrone(Game* p, int HP, int pow, int ID_, int cap, int Tj):
	ArmyUnit(p,HP,pow,ID_,cap,Tj)
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
	Stack<EarthTank*> temp_stack;
	priQueue<EarthGunnery*> temp_pri;
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
			else
				temp_stack.push(pET);
		}
	}
	EarthTank* tempET;
	while (!temp_stack.isEmpty())
	{
		temp_stack.pop(tempET);
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
				temp_pri.enqueue(pEG, pEG->GetPower() + pEG->GetHealth());
		}
	}
	EarthGunnery* tempEG;
	int x;
	while (!temp_pri.isEmpty())
	{
		temp_pri.dequeue(tempEG,x);
		pGame->Add_EG(tempEG);
	}
	return false;
}

ostream& operator<<(ostream& COUT, AlienDrone* PAssed_AD)
{
	COUT << PAssed_AD->GetID() << " ";
	return COUT;
}
