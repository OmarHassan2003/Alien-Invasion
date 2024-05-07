#include "AlienSoldier.h"
#include "../Game.h"

AlienSoldier::AlienSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, U)
{
}

void AlienSoldier::AddEarthUnitToList(EarthArmy* passed_EA)
{
}

void AlienSoldier::AddAlienUnitToList(AlienArmy* passed_AA)
{
	if(passed_AA)
		passed_AA->AddInQueue(this);
}

bool AlienSoldier::Attack()
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
			templist.enqueue(ES);
		}
		else
			break;
	if (pGame->Get_GameMode())
	{
		if (!templist.isEmpty())
		{
			cout << "AS " << this << "shots [";
			templist.print();
			cout << "]" << endl;
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

ostream& operator<<(ostream& COUT, AlienSoldier* Passed_AU)
{
	COUT << Passed_AU->GetID() << " ";
	return COUT;
}
