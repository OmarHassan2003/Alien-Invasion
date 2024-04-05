#pragma once
#include "RandomGenerator/RandomGenerator.h"
#include <fstream>
#include <iostream>
#include "EarthArmy/EarthArmy.h"
#include "AlienArmy/AlienArmy.h"
using namespace std;

class Game
{
	EarthArmy* EA;
	AlienArmy* AA;
	RandomGenerator* randgenn;
	unsigned short Tj_value;
	unsigned short n, ES, ET, EG, AS, AM, AD, Prop;

	unsigned short min_E_Power, min_E_health, min_E_Attack_Capacity;
	unsigned short max_E_Power, max_E_health, max_E_Attack_Capacity;

	unsigned short min_A_Power, min_A_health, min_A_Attack_Capacity;
	unsigned short max_A_Power, max_A_health, max_A_Attack_Capacity;
public:
	Game();
	void Generate_Earth_Army();
	void Generate_Alien_Army();
	unsigned short Get_And_Inc_Tj();
};

static void ReadData(unsigned short& n, unsigned short& ES,
	unsigned short& ET, unsigned short& EG, unsigned short& AS, unsigned short& AM, unsigned short& AD,
	unsigned short& Prop,
	unsigned short& min_E_Power, unsigned short& min_E_health, unsigned short& min_E_Attack_Capacity,
	unsigned short& max_E_Power, unsigned short& max_E_health, unsigned short& max_E_Attack_Capacity,
	unsigned short& min_A_Power, unsigned short& min_A_health, unsigned short& min_A_Attack_Capacity,
	unsigned short& max_A_Power, unsigned short& max_A_health, unsigned short& max_A_Attack_Capacity);

