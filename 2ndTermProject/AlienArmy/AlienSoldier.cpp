#include "AlienSoldier.h"
#include "../Game.h"

AlienSoldier::AlienSoldier(Game* p, double HP, double pow, int ID_, int cap, int _Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, U)
{
}

bool AlienSoldier::Attack()
{
	bool flag = false;
	EarthSoldier* ES = nullptr;
	SaverUnit* SU = nullptr;
	Queue<EarthSoldier*> templist1;
	Queue<SaverUnit*> templist2;
	int i;
	for (i = 0; i < GetAttackCap() / 2; i++)
	{
		if (pGame->Get_SU(SU))
		{
			flag = true;
			if (SU->Get_Ta() == -1)
				SU->Set_Ta(pGame->Get_Tj());

			double dmg = GetPower() * (GetHealth() / 100.0) / sqrt(SU->GetHealth());
			SU->SetHealth(SU->GetHealth() - dmg);
			templist2.enqueue(SU);
		}
		else
			break;
	}
	for (; i < GetAttackCap(); i++)
		if (pGame->Get_ES(ES))
		{
			flag = true;
			if (ES->Get_Ta() == -1)
				ES->Set_Ta(pGame->Get_Tj());

			double dmg = GetPower() * (GetHealth() / 100.0) / sqrt(ES->GetHealth());
			ES->SetHealth(ES->GetHealth() - dmg);
			templist1.enqueue(ES);
		}
		else
			break;
	if (pGame->Get_GameMode())
	{
		if (!templist1.isEmpty() || !templist2.isEmpty())
		{
			cout << "AS " << this << " shots ";
			templist1.print();
			cout << " ";
			templist2.print();
			cout << endl;
		}
	}
	while (templist1.dequeue(ES))
	{
		if (ES->GetHealth() <= 0)
			pGame->AddInKilledList(ES);
		else if (ES->GetHealth() < 0.2 * ES->GetInitialH())
			pGame->AddToESUML(ES);
		else
			pGame->Add_ES(ES);
	}
	while (templist2.dequeue(SU))
	{
		if (SU->GetHealth() <= 0)
			pGame->AddInKilledList(SU);
		else
			pGame->Add_SU(SU);
	}
	return flag;
}

ostream& operator<<(ostream& COUT, AlienSoldier* Passed_AU)
{
	COUT << Passed_AU->GetID();
	return COUT;
}
