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
#include "../HealUnit.h"

using namespace std;

class RandomGenerator
{
	unsigned short Tj_value;
	unsigned short HU_Percent;
	unsigned short n, ES, ET, EG, AS, AM, AD, Prop;

	unsigned short min_E_Power, min_E_health, min_E_Attack_Capacity;
	unsigned short max_E_Power, max_E_health, max_E_Attack_Capacity;

	unsigned short min_A_Power, min_A_health, min_A_Attack_Capacity;
	unsigned short max_A_Power, max_A_health, max_A_Attack_Capacity;
public:
	RandomGenerator();
	inline unsigned short RandGen(unsigned short lower_bound, unsigned short upper_bound);
	ArmyUnit* CreateUnit(unsigned short Tj, Game* pGame, char u);
	void set_n(int N);
	int get_n() const;
	void set_HU_percent(unsigned short h);
	unsigned short get_HU_percent() const;
	void set_ES(int es);
	void set_ET(int et);
	void set_EG(int eg);
	void set_AS(int as);
	void set_AM(int am);
	void set_AD(int ad);
	void set_Prop(int prop);
	int get_Prop() const;
	void set_MinEpower(int min_e_power);
	void set_MinEhealth(int min_e_health);
	void set_MinEAttackCapacity(int min_e_attackcapcity);
	void set_MaxEpower(int max_e_power);
	void set_MaxEhealth(int max_e_health);
	void set_MaxEAttackCapacity(int max_e_attackcapcity);
	void set_MinApower(int min_a_power);
	void set_MinAhealth(int min_a_health);
	void set_MinAAttackCapacity(int min_a_attackcapcity);
	void set_MaxApower(int max_a_power);
	void set_MaxAhealth(int max_a_health);
	void set_MaxAAttackCapacity(int max_a_attackcapcity);
};

