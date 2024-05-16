#include "EarthSoldier.h"
#include "../Game.h"

EarthSoldier::EarthSoldier(Game* p, double HP, double pow, int ID_, int cap, int _Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, U)
{
}

bool EarthSoldier::Attack() //PHASE2
{
	if (this->getInfected())
	{
		bool flag = false;
		EarthSoldier* ES = nullptr;
		Queue<EarthSoldier*> templist;
		for (int i = 0; i < GetAttackCap(); i++)
			if (pGame->Get_ES(ES))
			{
				flag = true;
				if (ES->Get_Ta() == -1)
					ES->Set_Ta(pGame->Get_Tj());

				double dmg = GetPower() * (GetHealth() / 100.0) / sqrt(ES->GetHealth());
				ES->SetHealth(ES->GetHealth() - dmg);
				templist.enqueue(ES);
			}
			else
				break;

		if (pGame->Get_GameMode())
		{
			if (!templist.isEmpty())
			{
				cout << "#ES " << this << " shots ";
				templist.print();
				cout << endl;
			}
		}
		while (templist.dequeue(ES))
		{
			if (ES->GetHealth() <= 0)
				pGame->AddInKilledList(ES);
			else if (ES->GetHealth() < 0.2 * ES->GetInitialH())
				pGame->AddToESUML(ES);
			else
				pGame->Add_ES(ES);
		}
		return flag;
	}
	else
	{
		bool flag = false;
		AlienSoldier* AS = nullptr;
		Queue<AlienSoldier*> templist;
		for (int i = 0; i < GetAttackCap(); i++)
			if (pGame->Get_AS(AS))
			{
				flag = true;
				if (AS->Get_Ta() == -1)
					AS->Set_Ta(pGame->Get_Tj());

				double dmg = GetPower() * (GetHealth() / 100.0) / sqrt(AS->GetHealth());
				AS->SetHealth(AS->GetHealth() - dmg);
				templist.enqueue(AS);
			}
			else
				break;

		if (pGame->Get_GameMode())
		{
			if (!templist.isEmpty())
			{
				cout << "ES " << this << " shots ";
				templist.print();
				cout << endl;
			}
		}
		while (templist.dequeue(AS))
		{
			if (AS->GetHealth() <= 0)
				pGame->AddInKilledList(AS);
			else
				pGame->Add_AS(AS);
		}
		return flag;
	}
}

void EarthSoldier::setInfected(bool inf)
{
	IsInfected = inf;
}

bool EarthSoldier::getInfected()
{
	return IsInfected;
}

void EarthSoldier::setImmune(bool imu)
{
	IsImmune = true;
}

bool EarthSoldier::getImmune()
{
	return IsImmune;
}

ostream& operator<<(ostream& COUT, EarthSoldier* Passed_AU)
{
	if (Passed_AU != NULL)
	{
		if (Passed_AU->getInfected())
			COUT << "#";
		COUT << Passed_AU->GetID();
		return COUT;
	}
}