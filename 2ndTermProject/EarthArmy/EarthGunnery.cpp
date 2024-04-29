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
	for (unsigned short i = 0;i < Attack_Cap;i++)
	{
		flag = true;
		if (pGame->Get_AD(pAD0))
		{
			pAD0->SetHealth(pAD0->GetHealth() - this->GetPower());
			if (pAD0->GetHealth() <= 0)
				pGame->AddInKilledList(pAD0);
			else
				temp_queue0.enqueue(pAD0);
		}
		if (pGame->Get_L_AD(pAD1))
		{
			pAD1->SetHealth(pAD1->GetHealth() - this->GetPower());
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
	/*******************************Drone Attack*******************************/
	Attack_Cap = GetAttackCap() - Attack_Cap;
	for (unsigned short i = 0;i < Attack_Cap;i++)
	{
		flag = true;
		if (pGame->Get_AM(pAM))
		{
			pAM->SetHealth(pAM->GetHealth() - this->GetPower());
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
