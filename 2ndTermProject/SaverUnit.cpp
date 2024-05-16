#include "SaverUnit.h"
#include "AlienArmy/AlienSoldier.h"
#include "Game.h"

SaverUnit::SaverUnit(Game* p, double HP, double pow, int ID_, int cap, int _Tj, Unit U)
	:ArmyUnit(p, HP, pow, ID_, cap, _Tj, U)
{
}

bool SaverUnit::Attack()
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
			cout << "SU " << this << " shots ";
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

ostream& operator<<(ostream& COUT, SaverUnit* Passed_AU)
{
	if (Passed_AU != NULL)
	{
		COUT << Passed_AU->GetID() << " ";
		return COUT;
	}
}