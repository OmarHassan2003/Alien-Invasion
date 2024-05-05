#include "EarthGunnery.h"
#include "../Game.h"

EarthGunnery::EarthGunnery(Game* p, int HP, int pow, int ID_, int cap, int Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, Tj, U)
{}

void EarthGunnery::AddEarthUnitToList(EarthArmy* passed_EA)
{
	passed_EA->AddInPriQueue(this);
}

void EarthGunnery::AddAlienUnitToList(AlienArmy* passed_AA)
{
}

void EarthGunnery::Increment_E_Destructed_Units(EarthArmy* passed_EA)
{
	passed_EA->Increment_Total_E_Destructed_Units();
}

void EarthGunnery::Increment_A_Destructed_Units(AlienArmy* passed_EA)
{}

bool EarthGunnery::Attack()
{
	bool flag = false;

	AlienDrone* pAD0, * pAD1;
	AlienMonster* pAM;
	Queue<AlienDrone*> temp_queue0;
	Queue<AlienDrone*> temp_queue1;
	Queue<AlienMonster*> temp_AM_Queue;

	unsigned short Attack_Cap = GetAttackCap() / 2;
	/*******************************Drone Attack*******************************/
	for (unsigned short i = 0;i < Attack_Cap / 2;i++)
	{
		flag = true;
		if (pGame->Get_AD(pAD0))
		{
			if (pAD0->Get_Ta() == -1)
				pAD0->Set_Ta(pGame->Get_Tj());

			int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(pAD0->GetHealth()));
			pAD0->SetHealth(pAD0->GetHealth() - dmg);
			if (pAD0->GetHealth() <= 0)
				pGame->AddInKilledList(pAD0);
			else
				temp_queue0.enqueue(pAD0);
		}
	}
	for (unsigned short i = 0;i < Attack_Cap - Attack_Cap / 2;i++)
	{
		flag = true;
		if (pGame->Get_L_AD(pAD1))
		{
			if (pAD1->Get_Ta() == -1)
				pAD1->Set_Ta(pGame->Get_Tj());

			int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(pAD1->GetHealth()));
			pAD1->SetHealth(pAD1->GetHealth() - dmg);
			if (pAD1->GetHealth() <= 0)
				pGame->AddInKilledList(pAD1);
			else
				temp_queue1.enqueue(pAD1);
		}
	}
	AlienDrone* tempAD;
	while (!temp_queue0.isEmpty())
	{
		temp_queue0.dequeue(tempAD);
		pGame->Add_AD(tempAD);
	}
	while (!temp_queue1.isEmpty())
	{
		temp_queue1.dequeue(tempAD);
		pGame->Add_AD_Front(tempAD);
	}
	/*******************************Monster Attack*******************************/
	Attack_Cap = GetAttackCap() - Attack_Cap;
	for (unsigned short i = 0;i < Attack_Cap;i++)
	{
		flag = true;
		if (pGame->Get_AM(pAM))
		{
			if (pAM->Get_Ta() == -1)
				pAM->Set_Ta(pGame->Get_Tj());

			int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(pAM->GetHealth()));
			pAM->SetHealth(pAM->GetHealth() - dmg);
			if (pAM->GetHealth() <= 0)
				pGame->AddInKilledList(pAM);
			else
				temp_AM_Queue.enqueue(pAM);
		}
	}
	AlienMonster* tempAM;
	while (!temp_AM_Queue.isEmpty())
	{
		temp_AM_Queue.dequeue(tempAM);
		pGame->Add_AM(tempAM);
	}
	return flag;
}

ostream& operator<<(ostream& COUT, EarthGunnery* Passed_AU)
{
	COUT << Passed_AU->GetID() << " ";
	return COUT;
}
