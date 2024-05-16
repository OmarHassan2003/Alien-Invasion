#include "EarthGunnery.h"
#include "../Game.h"

EarthGunnery::EarthGunnery(Game* p, double HP, double pow, int ID_, int cap, int Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, Tj, U)
{}

bool EarthGunnery::Attack()
{
	bool flag = false;

	AlienDrone* pAD0, * pAD1;
	AlienMonster* pAM;
	Queue<AlienDrone*> temp_queue0;
	Queue<AlienDrone*> temp_queue1;
	Queue<AlienMonster*> temp_AM_Queue;

	bool it = true;
	unsigned short Attack_Cap = GetAttackCap() / 2;
	unsigned short aid_counter = 0;
	/*******************************Drone Attack*******************************/
	for (unsigned short i = 0;i < Attack_Cap;i++)
	{
		if (it && pGame->Get_AD(pAD0))
		{
			flag = true;
			if (pAD0->Get_Ta() == -1)
				pAD0->Set_Ta(pGame->Get_Tj());

			double dmg = GetPower() * (GetHealth() / 100.0) / sqrt(pAD0->GetHealth());
			pAD0->SetHealth(pAD0->GetHealth() - dmg);
			temp_queue0.enqueue(pAD0);
			it = false;
			aid_counter++;
		}
		else if (!it && pGame->Get_L_AD(pAD1))
		{
			flag = true;
			if (pAD1->Get_Ta() == -1)
				pAD1->Set_Ta(pGame->Get_Tj());

			double dmg = GetPower() * (GetHealth() / 100.0) / sqrt(pAD1->GetHealth());
			pAD1->SetHealth(pAD1->GetHealth() - dmg);
			temp_queue1.enqueue(pAD1);
			it = true;
			aid_counter++;
		}
		else
			break;
	}
	/*******************************Monster Attack*******************************/
	Attack_Cap = GetAttackCap() - aid_counter;
	for (unsigned short i = 0;i < Attack_Cap;i++)
	{
		if (pGame->Get_AM(pAM))
		{
			flag = true;
			if (pAM->Get_Ta() == -1)
				pAM->Set_Ta(pGame->Get_Tj());

			double dmg = GetPower() * (GetHealth() / 100.0) / sqrt(pAM->GetHealth());
			pAM->SetHealth(pAM->GetHealth() - dmg);
			temp_AM_Queue.enqueue(pAM);
		}
		else
			break;
	}

	if (pGame->Get_GameMode())
	{
		if (!temp_queue0.isEmpty() || !temp_queue1.isEmpty() || !temp_AM_Queue.isEmpty())
		{
			cout << "EG " << this << " shots ";
			temp_queue0.print();
			cout << " ";
			temp_queue1.print();
			cout << " ";
			temp_AM_Queue.print();
			cout << endl;
		}
	}

	AlienDrone* tempAD;
	unsigned short i = 0;
	while (!temp_queue0.isEmpty())
	{
		temp_queue0.dequeue(tempAD);
		if (tempAD->GetHealth() <= 0)
			pGame->AddInKilledList(tempAD);
		else
		{
			if (i)
			{
				pGame->Add_AD(tempAD);
				i = 1;
			}
			else
			{
				pGame->Add_AD_Front(tempAD);
				i = 0;
			}
		}
	}
	while (!temp_queue1.isEmpty())
	{
		temp_queue1.dequeue(tempAD);
		if (tempAD->GetHealth() <= 0)
			pGame->AddInKilledList(tempAD);
		else
			if (i)
			{
				pGame->Add_AD(tempAD);
				i = 1;
			}
			else
			{
				pGame->Add_AD_Front(tempAD);
				i = 0;
			}
	}

	AlienMonster* tempAM;
	while (!temp_AM_Queue.isEmpty())
	{
		temp_AM_Queue.dequeue(tempAM);
		if (tempAM->GetHealth() <= 0)
			pGame->AddInKilledList(tempAM);
		else
			pGame->Add_AM(tempAM);
	}
	return flag;
}

ostream& operator<<(ostream& COUT, EarthGunnery* Passed_AU)
{
	COUT << Passed_AU->GetID();
	return COUT;
}
