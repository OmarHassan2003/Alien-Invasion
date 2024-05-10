#include "EarthSoldier.h"
#include "../Game.h"

EarthSoldier::EarthSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, U)
{
}

void EarthSoldier::AddEarthUnitToList(EarthArmy* passed_EA)
{
	if(passed_EA)
		passed_EA->AddInQueue(this);
}

void EarthSoldier::AddAlienUnitToList(AlienArmy* passed_AA)
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

				int dmg = int((float)GetPower() * (GetHealth() / 100.0) / (float)sqrt(ES->GetHealth()));
				ES->SetHealth(ES->GetHealth() - dmg);

				if (ES->GetHealth() <= 0)
					pGame->AddInKilledList(ES);
				else if (ES->GetHealth() < 0.2 * ES->GetInitialH())
					pGame->AddToESUML(ES);
				else
					templist.enqueue(ES);
			}
			else
				break;
		while (templist.dequeue(ES))
			pGame->Add_ES(ES);
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
		
				int dmg = int((float)GetPower()*(GetHealth()/100.0)/ (float)sqrt(AS->GetHealth()));
				AS->SetHealth(AS->GetHealth() - dmg);
			
				if (AS->GetHealth() <= 0)
					pGame->AddInKilledList(AS);
				else
					templist.enqueue(AS);
			}
			else
				break;
		while (templist.dequeue(AS))
			pGame->Add_AS(AS);
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
			COUT << "!";
		COUT << Passed_AU->GetID() << " ";
		return COUT;
	}
}