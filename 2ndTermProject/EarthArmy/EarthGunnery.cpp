#include "EarthGunnery.h"
#include "../Game.h"

EarthGunnery::EarthGunnery(Game* p, int HP, int pow, int ID_, int cap, int Tj)
	:ArmyUnit(p, HP, pow, ID_, cap, Tj)
{}

void EarthGunnery::AddEarthUnitToList(EarthArmy* passed_EA)
{
	passed_EA->AddInPriQueue(this);
}

void EarthGunnery::AddAlienUnitToList(AlienArmy* passed_AA)
{
}

bool EarthGunnery::Attack()
{
	bool flag = false;

	AlienDrone* pAD0, * pAD1;
	AlienMonster* pAM;
	Queue<AlienDrone*> temp_queue0;
	Queue<AlienDrone*> temp_queue1;
	DynamicArray<AlienMonster*> temp_arr;

	unsigned short Attack_Cap = GetAttackCap() / 2;
	/*******************************Drone Attack*******************************/
	for (unsigned short i = 0;i < Attack_Cap / 2;i++)
	{
		flag = true;
		if (pGame->Get_AD(pAD0))
		{
			int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(pAD0->GetHealth()));
			pAD0->SetHealth(pAD0->GetHealth() - dmg);
			cout << "pAD0->Heatlth = " << pAD0->GetHealth() << endl;
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
			int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(pAD1->GetHealth()));
			pAD1->SetHealth(pAD1->GetHealth() - dmg);
			cout << "pAD1->Heatlth = " << pAD1->GetHealth() << endl;
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
		cout << tempAD << endl;
		pGame->Add_AD(tempAD);
	}
	while (!temp_queue1.isEmpty())
	{
		temp_queue1.dequeue(tempAD);
		cout << tempAD << endl;
		pGame->Add_AD_Front(tempAD);
	}
	/*******************************Monster Attack*******************************/
	Attack_Cap = GetAttackCap() - Attack_Cap;
	for (unsigned short i = 0;i < Attack_Cap;i++)
	{
		flag = true;
		if (pGame->Get_AM(pAM))
		{
			int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(pAM->GetHealth()));
			pAM->SetHealth(pAM->GetHealth() - dmg);
			if (pAM->GetHealth() <= 0)
				pGame->AddInKilledList(pAM);
			else
				temp_arr.Add(pAM);
		}
	}
	AlienMonster* tempAM;
	while (!temp_arr.isEmpty())
	{
		temp_arr.Pick(tempAM);
		pGame->Add_AM(tempAM);
	}
	return flag;
}

ostream& operator<<(ostream& COUT, EarthGunnery* Passed_AU)
{
	COUT << Passed_AU->GetID() << " ";
	return COUT;
}
