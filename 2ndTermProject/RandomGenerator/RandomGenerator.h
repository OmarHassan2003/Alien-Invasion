#pragma once
#include <iostream>
#include <ctime>
#include "../EarthArmy/EarthGunnery.h"
#include "../EarthArmy/EarthTank.h"
#include "../EarthArmy/EarthSoldier.h"
#include "../AlienArmy/AlienDrone.h"
#include "../AlienArmy/AlienMonster.h"
#include "../AlienArmy/AlienSoldier.h"
#include "../ArmyUnit.h"

using namespace std;

class RandomGenerator
{
public:
	RandomGenerator();
	inline unsigned short RandGen(unsigned short lower_bound, unsigned short upper_bound);
	ArmyUnit* CreateUnit(unsigned short& unit1, unsigned short& unit2, unsigned short& unit3,
		unsigned short& min_Power, unsigned short& min_health, unsigned short& min_Attack_Capacity,
		unsigned short& max_Power, unsigned short& max_health, unsigned short& max_Attack_Capacity
		, unsigned short Tj, Game* pGame, char u);
};

