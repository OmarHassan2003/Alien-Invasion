#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
{
	cout << "Random Generator Class has been started" << endl;
}

inline unsigned short RandomGenerator::RandGen(unsigned short lower_bound, unsigned short upper_bound)
{
	srand(time(0));
	return lower_bound + rand() % (upper_bound - lower_bound + 1);
}

ArmyUnit* RandomGenerator::CreateUnit(unsigned short& unit1, unsigned short& unit2, unsigned short& unit3,
	unsigned short& min_Power, unsigned short& min_health, unsigned short& min_Attack_Capacity,
	unsigned short& max_Power, unsigned short& max_health, unsigned short& max_Attack_Capacity,
	unsigned short Tj, ArmyUnit::Unit ut)
{
	ArmyUnit* pArmyUnit;
	if (ut == 0)
	{
		static unsigned short EarthID = 1;
		unsigned short x = RandGen(1, 100);
		unsigned short health = RandGen(min_health, max_health);
		unsigned short power = RandGen(min_Power, max_Power);
		unsigned short attack_capacity = RandGen(min_Attack_Capacity, max_Attack_Capacity);
		if (x <= unit1)
			pArmyUnit = new EarthSoldier(pGame, health, power, EarthID, attack_capacity, Tj);
		else if (x <= unit1 + unit2)
			pArmyUnit = new EarthTank(pGame, health, power, EarthID, attack_capacity, Tj);
		else
			pArmyUnit = new EarthGunnery(pGame, health, power, EarthID, attack_capacity, Tj);
		EarthID++;
	}
	else
	{
		static unsigned short AlienID = 2000;
		unsigned short x = RandGen(1, 100);
		unsigned short health = RandGen(min_health, max_health);
		unsigned short power = RandGen(min_Power, max_Power);
		unsigned short attack_capacity = RandGen(min_Attack_Capacity, max_Attack_Capacity);
		if (x <= unit1)
			pArmyUnit = new AlienSoldier(pGame, health, power, AlienID, attack_capacity, Tj);
		else if (x <= unit1 + unit2)
			pArmyUnit = new AlienMonster(pGame, health, power, AlienID, attack_capacity, Tj);
		else
			pArmyUnit = new AlienDrone(pGame, health, power, AlienID, attack_capacity, Tj);;
		AlienID++;
	}
	return pArmyUnit;
}
