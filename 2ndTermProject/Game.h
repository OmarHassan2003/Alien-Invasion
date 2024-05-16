#pragma once
#include "RandomGenerator/RandomGenerator.h"
#include <fstream>
#include <iostream>
#include "EarthArmy/EarthArmy.h"
#include "AlienArmy/AlienArmy.h"
#include "AlliedArmy.h"
using namespace std;

class Game
{
	EarthArmy* EA;
	AlienArmy* AA;
	AlliedArmy* Allies;
	Queue<ArmyUnit*> Killed_List;
	priQueue<ArmyUnit*> ES_UML; // HERE or in EA class.
	Queue<ArmyUnit*> ET_UML; // HERE or in EA class.
	RandomGenerator* randgenn;
	unsigned short Tj_value;
	unsigned short HealedUnits = 0;
	bool gameMode;
public:
	Game();
	void IncInfectedES();
	void Battle();
	void ReadData();
	bool GameMode();
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
	bool Get_SU(SaverUnit*& AU);
	EarthArmy* getEA_ptr();
	AlienArmy* getAA_ptr();
	AlliedArmy* getAllies_ptr();
	bool Get_ET(EarthTank*& AU);
	bool Get_L_AD(AlienDrone*& AU);
	bool Get_ES_UML(ArmyUnit*& AU);
	bool Get_ET_UML(ArmyUnit*& AU);
	bool Get_GameMode() const;
	/////////////////////////////////////
	int Get_Count(ArmyUnit::Unit U);
	int countDestructed(ArmyUnit::Unit U);
	/////////////////////////////////////
	void AddToESUML(ArmyUnit* passed_AU);
	void AddToETUML(ArmyUnit* passed_AU);
	void Add_ES(EarthSoldier* AU);
	void Add_ET(EarthTank* AU);
	void Add_AS(AlienSoldier* AU);
	void Add_SU(SaverUnit* SU);
	void Add_AD(AlienDrone* AU);
	void Add_AD_Front(AlienDrone* AU);

	void Add_AM(AlienMonster* AU);
	void Add_EG(EarthGunnery* AU);
	/////////////////////////////////////
	bool Attack();
	bool WillInfect();
	void SU_Withdrawal();
	void printArmies();
	void printUMLQueue();
	void printKilledList();
	/////////////////////////////////////
	void GenerateOutputFile();
	~Game();
};