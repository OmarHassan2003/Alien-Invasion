#pragma once
#include "RandomGenerator/RandomGenerator.h"
#include <fstream>
#include <iostream>
#include "EarthArmy/EarthArmy.h"
#include "AlienArmy/AlienArmy.h"
using namespace std;

class Game
{
	EarthArmy EA;
	AlienArmy AA;
	Queue<ArmyUnit*> Killed_List;
	priQueue<ArmyUnit*> UML;
	RandomGenerator* randgenn;
	unsigned short Tj_value;
	int Max_E_HP;
public:
	Game();
	void ReadData();
	void Generate_Earth_Army();
	void Generate_Alien_Army();
	unsigned short Get_And_Inc_Tj();
	unsigned short Get_Tj();
	void AddInKilledList(ArmyUnit* passed_AU);
	bool AddToUML(ArmyUnit* passed_AU, int pri);
	void process_ES();
	void process_ET();
	void process_EG();
	void process_AS();
	void process_AD();
	void process_AM();
	bool CheckWhoWins();
	bool Get_AS(AlienSoldier* AU);
	bool Get_ES(EarthSoldier* AU);
	bool GetUML(ArmyUnit* AU, int pri);
	void Attack();
	void EA_Attack_AA();
	void print();
	~Game();
};