#include "Game.h"

Game::Game()
{
	randgenn = new RandomGenerator; // could be deleted??
	Tj_value = 0;
	ReadData(n, ES,ET, EG, AS, AM, AD,Prop,min_E_Power, min_E_health, min_E_Attack_Capacity,max_E_Power,
	max_E_health, max_E_Attack_Capacity,min_A_Power,  min_A_health, min_A_Attack_Capacity, 
	max_A_Power,  max_A_health, max_A_Attack_Capacity);
}

void Game::Generate_Earth_Army()
{
	ArmyUnit* AU = nullptr;
	unsigned short x = randgenn->RandGen(1, 100);
	if (x <= Prop)
	{
		for (unsigned short i = 0; i < n; i++)
		{
			AU = randgenn->CreateUnit(ES, ET, EG, min_E_health, min_E_Attack_Capacity, min_E_Power, max_E_Power,
				max_E_health, max_E_Attack_Capacity, Tj_value, this, 'E');
			EA.AddUnit(AU);
		}
	}
}

void Game::Generate_Alien_Army()
{
	ArmyUnit* AU = nullptr;
	unsigned short x = randgenn->RandGen(1, 100);
	if (x <= Prop)
	{
		for (unsigned short i = 0; i < n; i++)
		{
			AU = randgenn->CreateUnit(AS, AM, AD, min_A_health, min_A_Attack_Capacity, min_A_Power, max_A_Power,
				max_E_health, max_E_Attack_Capacity, Tj_value, this, 'A');
			AA.AddUnit(AU);
		}
	}
}

unsigned short Game::Get_And_Inc_Tj()
{
	Tj_value++;
	return Tj_value;
}

unsigned short Game::Get_Tj()
{
	return Tj_value;
}

void Game::AddInKilledList(ArmyUnit* passed_AU)
{
	Killed_List.enqueue(passed_AU);
}

void Game::process_ES()
{
	EarthSoldier* temp;
	if(EA.pick_ES(temp))
		EA.InsertES(temp);
}

void Game::process_ET()
{
	EarthTank* temp;
	EA.pick_ET(temp);
	if (temp)
	{
		ArmyUnit* doubletemp = (ArmyUnit*)temp;
		Killed_List.enqueue(temp);
	}
}
void Game::process_EG()
{
	EarthGunnery* temp;
	if (EA.pick_EG(temp))
	{
		ArmyUnit* ultra_temp = (ArmyUnit*)temp;
		ultra_temp->SetHealth(temp->GetHealth() / 2);
		EA.InsertEG(temp);
	}
}

void Game::process_AS()
{
	Queue<AlienSoldier*>temp;
	for (int i = 1; i <= 5; i++)
	{
		AlienSoldier* dec = AA.Remove_AS();
		if (dec) 
		{
			ArmyUnit* doubletemp = (ArmyUnit*)dec;
			doubletemp->SetHealth(doubletemp->GetHealth() / 2);
			temp.enqueue(dec);
		}
	}
	cout << "The soldiers enqueued to the temp list are : " << '\n';
	while (!temp.isEmpty())
	{
		AlienSoldier* temporary;
		temp.dequeue(temporary);
		ArmyUnit* ultra_temp = (ArmyUnit*)temporary;
		if (ultra_temp)
		{
			cout << ultra_temp->GetID() << " , ";
			AA.InsertAS(temporary);
		}
	}
	cout << endl;
}

void Game::process_AD()
{
	for (int x = 2; x < 8; x++)
	{
		AlienDrone* temp = NULL;
		temp = AA.pick_AD(x);
		if (temp)
			Killed_List.enqueue(temp);
		else break;
	}
}

void Game::process_AM()
{
	AlienMonster* temp = NULL;
	if (AA.RETAMCOUNT() != 0)
	{
		temp = AA.pick_AM();
		if (temp)
			AA.AddInAmArray(temp);
	}
}

void Game::Attack()
{
	int x = 5;
	EarthGunnery* pEG;
	EA.pick_EG(pEG);
	AlienDrone* pAD0 = AA.pick_AD(x), * pAD1 = AA.pick_Rear_AD(x);
	AlienMonster* pAM = AA.pick_AM();
	if (pEG)
	{
		pEG->Attack(pAM);
		pEG->Attack(pAD0, pAD1);
		if (pAM->GetHealth() <= 0)
			AddInKilledList(pAM);
		if (pAD0->GetHealth() <= 0)
			AddInKilledList(pAD0);
		if (pAD1->GetHealth() <= 0)
			AddInKilledList(pAD1);
	}
	if (pAD0 && pAD1)
	{
		pAD0->Attack(pEG);
		pAD1->Attack(pEG);
		if (pEG->GetHealth() <= 0)
			AddInKilledList(pEG);
	}

}

bool Game::CheckWhoWins()
{
	if (EA.isCompromised())
	{
		cout << "Alien Army has won the game" << endl;
		return true;
	}
	else if (AA.isComromised())
	{
		cout << "Earth Army has won the game" << endl;
		return true;
	}
	else
		return false;
}

bool Game::Get_AS(AlienSoldier* AU) //PHASE2
{
	if (AA.pick_AS(AU))
		return true;
	else
		return false;
}

bool Game::Get_ES(EarthSoldier* AU)
{
	if (EA.pick_ES(AU))
		return true;
	else
		return false;
}
void Game::print()
{
	cout << "============================================ Earth Army Alive Units ==========================================" << endl;
	EA.PrintArmyInfo();
	cout << endl;
	cout << "============================================ Alien Army Alive Units ==========================================" << endl;
	AA.PrintArmyInfo();
	cout << endl;
	cout << "============================================ Killed/Destructed Units ==========================================" << endl;
	cout << Killed_List.GetCount() << " units [";
	Killed_List.print();
	cout << "]" << endl;
	cout << "===============================================================================================================" << endl;
}

Game::~Game()
{
	delete randgenn;
}

void ReadData(unsigned short& n, unsigned short& ES, unsigned short& ET, unsigned short& EG, unsigned short& AS, unsigned short& AM, unsigned short& AD, unsigned short& Prop, unsigned short& min_E_Power,
	unsigned short& min_E_health, unsigned short& min_E_Attack_Capacity, unsigned short& max_E_Power, unsigned short& max_E_health, unsigned short& max_E_Attack_Capacity, unsigned short& min_A_Power,
	unsigned short& min_A_health, unsigned short& min_A_Attack_Capacity, unsigned short& max_A_Power, unsigned short& max_A_health, unsigned short& max_A_Attack_Capacity)
{
	ifstream Fin("../test.txt");
	if (Fin.is_open())
	{
		Fin >> n >> ES >> ET >> EG >> AS >> AM >> AD >> Prop;
		/***********************Read Earth Data*************************/
		Fin >> min_E_Power;
		Fin.ignore();

		Fin >> max_E_Power;
		Fin.ignore();

		Fin >> min_E_health;
		Fin.ignore();

		Fin >> max_E_health;
		Fin.ignore();

		Fin >> min_E_Attack_Capacity;
		Fin.ignore();

		Fin >> max_E_Attack_Capacity;
		Fin.ignore();
		/***********************Read Earth Data*************************/
		/***********************Read ALien Data*************************/
		Fin >> min_A_Power;
		Fin.ignore();

		Fin >> max_A_Power;
		Fin.ignore();

		Fin >> min_A_health;
		Fin.ignore();

		Fin >> max_A_health;
		Fin.ignore();

		Fin >> min_A_Attack_Capacity;
		Fin.ignore();

		Fin >> max_A_Attack_Capacity;
		Fin.ignore();
		/***********************Read ALien Data*************************/
		Fin.close();
	}
	else
		cout << "File failed" << endl;
}
