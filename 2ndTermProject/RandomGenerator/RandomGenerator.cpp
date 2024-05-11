#include "RandomGenerator.h"
#include "../Game.h"
RandomGenerator::RandomGenerator()
{
	srand(time(0));
}

inline unsigned short RandomGenerator::RandGen(unsigned short lower_bound, unsigned short upper_bound)
{	
	return lower_bound + rand() % (upper_bound - lower_bound + 1);
}

ArmyUnit* RandomGenerator::CreateUnit(unsigned short Tj, Game* pGame, char u)
{
	ArmyUnit* pArmyUnit = nullptr;
	if (u == 'E')
	{
		static unsigned short EarthID = 1;
		unsigned short x = RandGen(1, 100);
		unsigned short health = RandGen(min_E_health, max_E_health);
		unsigned short power = RandGen(min_E_Power, max_E_Power);
		unsigned short attack_capacity = RandGen(min_E_Attack_Capacity, max_E_Attack_Capacity);
		if (EarthID == 1000  && pGame->Get_GameMode())
		{
			cout << "NO MORE IDS AVAILABLE FOR EARTH ARMY" << endl;
			return NULL;
		}
		if (x <= ES)
			pArmyUnit = new EarthSoldier(pGame, health, power, EarthID, attack_capacity, Tj);
		else if (x <= ES + ET)
			pArmyUnit = new EarthTank(pGame, health, power, EarthID, attack_capacity, Tj);
		else if (x <= ES + ET + HU_Percent)
			pArmyUnit = new HealUnit(pGame, health, power, EarthID, attack_capacity, Tj);
		else
			pArmyUnit = new EarthGunnery(pGame, health, power, EarthID, attack_capacity, Tj);
		EarthID++;
	}
	else
	{
		static unsigned short AlienID = 2001;
		unsigned short x = RandGen(1, 100);
		unsigned short health = RandGen(min_A_health, max_A_health);
		unsigned short power = RandGen(min_A_Power, max_A_Power);
		unsigned short attack_capacity = RandGen(min_A_Attack_Capacity, max_A_Attack_Capacity);
		if (AlienID == 3000 && pGame->Get_GameMode())
		{
			cout << "NO MORE IDS AVAILABLE FOR ALIEN ARMY" << endl;
			return NULL;
		}
		if (x <= AS)
			pArmyUnit = new AlienSoldier(pGame, health, power, AlienID, attack_capacity, Tj);
		else if (x <= AS + AM)
			pArmyUnit = new AlienMonster(pGame, health, power, AlienID, attack_capacity, Tj);
		else
			pArmyUnit = new AlienDrone(pGame, health, power, AlienID, attack_capacity, Tj);;
		AlienID++;
	}
	return pArmyUnit;
}

void RandomGenerator::set_n(int N)
{
	n = N;
}

int RandomGenerator::get_n() const
{
	return n;
}

void RandomGenerator::set_HU_percent(unsigned short h)
{
	HU_Percent = h;
}

unsigned short RandomGenerator::get_HU_percent() const
{
	return HU_Percent;
}

void RandomGenerator::set_ES(int es)
{
	ES = es;
}

void RandomGenerator::set_ET(int et)
{
	ET = et;
}

void RandomGenerator::set_EG(int eg)
{
	EG = eg;
}

void RandomGenerator::set_AS(int as)
{
	AS = as;
}

void RandomGenerator::set_AM(int am)
{
	AM = am;
}

void RandomGenerator::set_AD(int ad)
{
	AD = ad;
}

void RandomGenerator::set_Prop(int prop)
{
	Prop = prop;
}

int RandomGenerator::get_Prop() const
{
	return Prop;
}

void RandomGenerator::set_MinEpower(int min_e_power)
{
	min_E_Power = min_e_power;
}

void RandomGenerator::set_MinEhealth(int min_e_health)
{
	min_E_health = min_e_health;
}

void RandomGenerator::set_MinEAttackCapacity(int min_e_attackcapcity)
{
	min_E_Attack_Capacity = min_e_attackcapcity;
}

void RandomGenerator::set_MaxEpower(int max_e_power)
{
	max_E_Power = max_e_power;
}

void RandomGenerator::set_MaxEhealth(int max_e_health)
{
	max_E_health = max_e_health;
}

void RandomGenerator::set_MaxEAttackCapacity(int max_e_attackcapcity)
{
	max_E_Attack_Capacity = max_e_attackcapcity;
}

void RandomGenerator::set_MinApower(int min_a_power)
{
	min_A_Power = min_a_power;
}

void RandomGenerator::set_MinAhealth(int min_a_health)
{
	min_A_health = min_a_health;
}

void RandomGenerator::set_MinAAttackCapacity(int min_a_attackcapcity)
{
	min_A_Attack_Capacity = min_a_attackcapcity;
}

void RandomGenerator::set_MaxApower(int max_a_power)
{
	max_A_Power = max_a_power;
}

void RandomGenerator::set_MaxAhealth(int max_a_health)
{
	max_A_health = max_a_health;
}

void RandomGenerator::set_MaxAAttackCapacity(int max_a_attackcapcity)
{
	max_A_Attack_Capacity = max_a_attackcapcity;
}
