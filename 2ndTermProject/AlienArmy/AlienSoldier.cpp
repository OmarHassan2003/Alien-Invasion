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

void AlienSoldier::Increment_E_Destructed_Units(EarthArmy* passed_EA)
{}

void AlienSoldier::Increment_A_Destructed_Units(AlienArmy * passed_EA)
{
	if(passed_EA)
		passed_EA->Increment_Total_A_Destructed_Units();
}

bool AlienSoldier::Attack()
{
	bool flag = 1;
	EarthSoldier* ES = nullptr;
	Queue<EarthSoldier*> templist;
	for (int i = 0; i < GetAttackCap(); i++)
		if (pGame->Get_ES(ES))
		{
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
		{
			flag = 0;
			break;
		}
	while (templist.dequeue(ES))
		pGame->Add_ES(ES);
	return flag;
}

ostream& operator<<(ostream& COUT, AlienSoldier* Passed_AU)
{
	COUT << Passed_AU->GetID() << " ";
	return COUT;
}
