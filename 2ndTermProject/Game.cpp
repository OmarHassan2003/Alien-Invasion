#include "Game.h"

Game::Game()
{
	randgenn = new RandomGenerator;
	Tj_value = 0;
	ReadData();
}

void Game::Generate_Earth_Army()
{
	ArmyUnit* AU = nullptr;
	unsigned short x = randgenn->RandGen(1, 100);
	if (x <= randgenn->get_Prop())
	{
		for (unsigned short i = 0; i < randgenn->get_n(); i++)
		{
			AU = randgenn->CreateUnit(Tj_value, this, 'E');
			EA.AddUnit(AU);
		}
	}
}

void Game::Generate_Alien_Army()
{
	ArmyUnit* AU = nullptr;
	unsigned short x = randgenn->RandGen(1, 100);
	if (x <= randgenn->get_Prop())
	{
		for (unsigned short i = 0; i < randgenn->get_n(); i++)
		{
			AU = randgenn->CreateUnit(Tj_value, this, 'A');
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
		if (ultra_temp->GetHealth() <= 0)
			Killed_List.enqueue(temp);
		else EA.InsertEG(temp);
	}
}

void Game::process_AS()
{
	Queue<AlienSoldier*>temp;
	for (int i = 1; i <= 5; i++)
	{
		AlienSoldier* dec;
		if (AA.pick_AS(dec))
		{
			ArmyUnit* doubletemp = (ArmyUnit*)dec;
			doubletemp->SetHealth(doubletemp->GetHealth() / 2);
			if (doubletemp->GetHealth() <= 0)
				Killed_List.enqueue(dec);
			else
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
	for (int x = 1; x <= 3; x++)
	{
		AlienDrone* temp = NULL;
		AlienDrone* doubleTemp = NULL;
		doubleTemp = AA.pick_AD(temp);
		if (temp)
			Killed_List.enqueue(temp);
		if (doubleTemp)
			Killed_List.enqueue(doubleTemp);
	}
}

void Game::process_AM()
{
	AlienMonster* temp;
	if (AA.pick_AM(temp))
		AA.AddInAmArray(temp);
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
	while (!Killed_List.isEmpty())
	{
		ArmyUnit* temp;
		Killed_List.dequeue(temp);
		delete temp;
	}
}

void Game::ReadData()
{
	unsigned short n, ES, ET, EG, AS, AM, AD, Prop, min_E_Power, min_E_health, min_E_Attack_Capacity, max_E_Power,
		max_E_health, max_E_Attack_Capacity, min_A_Power, min_A_health, min_A_Attack_Capacity, max_A_Power,
		max_A_health, max_A_Attack_Capacity;
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
		/***********************Create the random generator object*************************/
		randgenn->set_n(n);
		randgenn->set_ES(ES);
		randgenn->set_ET(ET);
		randgenn->set_EG(EG);
		randgenn->set_AS(AS);
		randgenn->set_AM(AM);
		randgenn->set_AD(AD);
		randgenn->set_Prop(Prop);
		randgenn->set_MinEpower(min_E_Power);
		randgenn->set_MinEhealth(min_E_health);
		randgenn->set_MinEAttackCapacity(min_E_Attack_Capacity);
		randgenn->set_MaxEpower(max_E_Power);
		randgenn->set_MaxEhealth(max_E_health);
		randgenn->set_MaxEAttackCapacity(max_E_Attack_Capacity);
		randgenn->set_MinApower(min_A_Power);
		randgenn->set_MinAhealth(min_A_health);
		randgenn->set_MinAAttackCapacity(min_A_Attack_Capacity);
		randgenn->set_MaxApower(max_A_Power);
		randgenn->set_MaxAhealth(max_A_health);
		randgenn->set_MaxAAttackCapacity(max_A_Attack_Capacity);
	}
	else
		cout << "File failed" << endl;
}