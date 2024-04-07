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
			AU = randgenn->CreateUnit(AS, AM, AD, min_A_health, min_A_Attack_Capacity, min_A_Power, max_A_Power,
				max_E_health, max_E_Attack_Capacity, Tj_value, this, 'A');
		AA.AddUnit(AU);
	}
}

unsigned short Game::Get_And_Inc_Tj()
{
	Tj_value++;
	return Tj_value;
}

void Game::AddInKilledList(ArmyUnit* passed_AU)
{
	Killed_List.enqueue(passed_AU);
}

void Game::process_ES()
{
	EarthSoldier* temp;
	temp = EA.pick_ES();
	EA.InsertES(temp);
}

void Game::process_ET()
{
	EarthTank* temp;
	temp = EA.pick_ET();
	Killed_List.enqueue(temp);
}

void Game::process_EG()
{
	EarthGunnery* temp;
	temp = EA.pick_EG();
	if (temp)
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
		temp.enqueue(AA.pick_AS());
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
		AlienDrone* temp = AA.pick_AD(x);
		if (temp)
			Killed_List.enqueue(temp);
	}
}

void Game::process_AM()
{
	AlienMonster* temp;
	temp = AA.pick_AM();
	AA.AddInAmArray(temp);
}

void Game::print()
{
	cout << "====================== Earth Army Alive Units ====================" << endl;
	EA.PrintArmyInfo();
	cout << endl;
	cout << "====================== Alien Army Alive Units ====================" << endl;
	AA.PrintArmyInfo();
}

//int Game::amcnt()
//{
//	return AA.RETAMCOUNT();
//}

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
