#include "Game.h"

Game::Game()
{
	EA = new EarthArmy;
	AA = new AlienArmy;
	randgenn = new RandomGenerator; // could be deleted??
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
				max_E_health, max_E_Attack_Capacity, Tj_value, ArmyUnit::ES);
			EA->AddUnit(this, AU);
		}
	}
}

void Game::Generate_Alien_Army()
{
	ArmyUnit* AU = nullptr;
	unsigned short x = randgenn->RandGen(1, 100);
	if (x <= Prop)
	{
		for (unsigned short i = 0;i < n;i++)
			AU = randgenn->CreateUnit(AS, AM, AD, min_A_health, min_A_Attack_Capacity, min_A_Power, max_A_Power,
				max_E_health, max_E_Attack_Capacity, Tj_value, ArmyUnit::AS);
		AA->AddUnit(this, AU);
	}
}

unsigned short Game::Get_And_Inc_Tj()
{
	Tj_value++;
	return Tj_value;
}

void Game::print()
{
	EA->PrintArmyInfo();
	AA->PrintArmyInfo();
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
