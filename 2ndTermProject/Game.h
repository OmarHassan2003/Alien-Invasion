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
	priQueue<ArmyUnit*> ES_UML; // HERE or in EA class.
	Queue<ArmyUnit*> ET_UML; // HERE or in EA class.
	RandomGenerator* randgenn;
	unsigned short Tj_value;
public:
	Game();
	void Battle();
	void ReadData();
	bool GameMode();
	void Generate_Earth_Army();
	void Generate_Alien_Army();
	unsigned short Get_And_Inc_Tj();
	unsigned short Get_Tj();
	void UpdateUML();
	void AddInKilledList(ArmyUnit* passed_AU);
	bool CheckWhoWins();
	/////////////////////////////////////
	bool Get_AM(AlienMonster*& AU);
	bool Get_AS(AlienSoldier*& AU);
	bool Get_ES(EarthSoldier*& AU);
	bool Get_EG(EarthGunnery*& AU);
	bool Get_AD(AlienDrone*& AU);
	bool Get_ET(EarthTank*& AU);
	bool Get_L_AD(AlienDrone*& AU);
	bool Get_ES_UML(ArmyUnit* AU);
	bool Get_ET_UML(ArmyUnit* AU);
	/////////////////////////////////////
	int Get_ES_Count();
	int Get_AS_Count();
	/////////////////////////////////////
	void AddToESUML(ArmyUnit* passed_AU);
	void AddToETUML(ArmyUnit* passed_AU);
	void Add_ES(EarthSoldier* AU);
	void Add_ET(EarthTank* AU);
	void Add_AS(AlienSoldier* AU);

	void Add_AD(AlienDrone* AU);
	void Add_AD_Front(AlienDrone* AU);

	void Add_AM(AlienMonster* AU);
	void Add_EG(EarthGunnery* AU);
	/////////////////////////////////////
	void Attack();
	void print();
	/////////////////////////////////////
	void GenerateOutputFile();
	~Game();
};