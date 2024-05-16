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

ArmyUnit* RandomGenerator::GenerateEarthUnit(int ID, Game* pGame, int Tj)
{
	ArmyUnit* pArmyUnit = nullptr;
	unsigned short x = RandGen(1, 100);
	double health = RandGen(min_E_health, max_E_health);
	double power = RandGen(min_E_Power, max_E_Power);
	unsigned short attack_capacity = RandGen(min_E_Attack_Capacity, max_E_Attack_Capacity);
	if (x <= ES)
		pArmyUnit = new EarthSoldier(pGame, health, power, ID, attack_capacity, Tj);
	else if (x <= ES + ET)
		pArmyUnit = new EarthTank(pGame, health, power, ID, attack_capacity, Tj);
	else if (x <= ES + ET + HU_Percent)
		pArmyUnit = new HealUnit(pGame, health, power, ID, attack_capacity, Tj);
	else
		pArmyUnit = new EarthGunnery(pGame, health, power, ID, attack_capacity, Tj);

	return pArmyUnit;
}

ArmyUnit* RandomGenerator::GenerateAlienUnit(int ID, Game* pGame, int Tj)
{
	ArmyUnit* pArmyUnit = nullptr;
	unsigned short x = RandGen(1, 100);
	double health = RandGen(min_A_health, max_A_health);
	double power = RandGen(min_A_Power, max_A_Power);
	unsigned short attack_capacity = RandGen(min_A_Attack_Capacity, max_A_Attack_Capacity);
	if (x <= AS)
		pArmyUnit = new AlienSoldier(pGame, health, power, ID, attack_capacity, Tj);
	else if (x <= AS + AM)
		pArmyUnit = new AlienMonster(pGame, health, power, ID, attack_capacity, Tj);
	else
		pArmyUnit = new AlienDrone(pGame, health, power, ID, attack_capacity, Tj);;

	return pArmyUnit;
}

ArmyUnit* RandomGenerator::GenerateSaverUnit(int ID, Game* pGame, int Tj)
{
	ArmyUnit* pArmyUnit = nullptr;
	unsigned short x = RandGen(1, 100);
	double health = RandGen(min_SU_health, max_SU_health);
	double power = RandGen(min_SU_Power, max_SU_Power);
	unsigned short attack_capacity = RandGen(min_SU_Attack_Capacity, max_SU_Attack_Capacity);
	pArmyUnit = new SaverUnit(pGame, health, power, ID, attack_capacity, Tj);
	return pArmyUnit;
}



bool RandomGenerator::AddUnits(Game* pGame, int Tj)
{
	ArmyUnit* pArmyUnit = nullptr;
	static unsigned short EarthID = 1;
	static unsigned short AlienID = 2001;
	static unsigned short SaverUnitID = 1001;
	bool gen_Earth = true;
	bool gen_Alien = true;
	bool gen_Saver = true;
	if (pGame->Get_GameMode())
	{
		if (EarthID == 1000)
		{
			cout << "NO MORE IDS AVAILABLE FOR EARTH ARMY" << endl;
			gen_Earth = false;
		}
		if (AlienID == 3000)
		{
			cout << "NO MORE IDS AVAILABLE FOR ALIEN ARMY" << endl;
			gen_Alien = false;
		}
		if (SaverUnitID == 1250)
		{
			cout << "NO MORE IDS AVAILABLE FOR ALLIES ARMY" << endl;
			gen_Saver = false;
		}
	}

	unsigned short x = RandGen(1, 100);
	if (x <= Prop)
	{
		for (unsigned short i = 0; i < n && gen_Earth; i++)
		{
			if (EarthID == 1000)
			{
				if(pGame->Get_GameMode())
					cout << "NO MORE IDS AVAILABLE FOR EARTH ARMY" << endl;
				gen_Earth = false;
			}
			else
			{
				pArmyUnit = GenerateEarthUnit(EarthID, pGame, Tj);
				pGame->getEA_ptr()->AddUnit(pArmyUnit);
				EarthID++;
			}
		}
	}

	unsigned short y = RandGen(1, 100);
	if (x <= Prop)
	{
		for (unsigned short i = 0; i < n && gen_Alien; i++)
		{
			if (AlienID == 3000)
			{
				if(pGame->Get_GameMode())
					cout << "NO MORE IDS AVAILABLE FOR ALIEN ARMY" << endl;
				gen_Alien = false;
			}
			else
			{
				pArmyUnit = GenerateAlienUnit(AlienID, pGame, Tj);
				pGame->getAA_ptr()->AddUnit(pArmyUnit);
				AlienID++;
			}
		}
	}

	int tot_count = pGame->getEA_ptr()->ES_Count();
	double inf_count = pGame->getEA_ptr()->ES_Infected_Count();
	if (tot_count != 0)
	{
		double inf_prcnt = (inf_count / float(tot_count)) * 100;
		if (inf_prcnt >= Threshold)
		{
			unsigned short y = RandGen(1, 100);
			if (x <= Prop)
			{
				for (unsigned short i = 0; i < n && gen_Saver; i++)
				{
					if (SaverUnitID == 1250)
					{
						if(pGame->Get_GameMode())
							cout << "NO MORE IDS AVAILABLE FOR ALLIES ARMY" << endl;
						gen_Saver = false;
					}
					else
					{
						pArmyUnit = GenerateSaverUnit(SaverUnitID, pGame, Tj);
						pGame->getAllies_ptr()->AddUnit(pArmyUnit);
						SaverUnitID++;
					}
				}
			}
		}
		return gen_Earth || gen_Alien;
	}
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

void RandomGenerator::set_InfectionProbaility(int inf)
{
	InfectionProbaility = inf;
}

void RandomGenerator::set_Threshold(int thres)
{
	Threshold = thres;
}

int RandomGenerator::get_Prop() const
{
	return Prop;
}

int RandomGenerator::get_InfectionProbability() const
{
	return InfectionProbaility;
}

int RandomGenerator::get_Threshold() const
{
	return Threshold;
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

void RandomGenerator::set_MinSUpower(int min_su_power)
{
	min_SU_Power = min_su_power;
}

void RandomGenerator::set_MinSUhealth(int min_su_health)
{
	min_SU_health = min_su_health;
}

void RandomGenerator::set_MinSUAttackCapacity(int min_su_attackcapcity)
{
	min_SU_Attack_Capacity = min_su_attackcapcity;
}

void RandomGenerator::set_MaxSUpower(int max_su_power)
{
	max_SU_Power = max_su_power;
}

void RandomGenerator::set_MaxSUhealth(int max_su_health)
{
	max_SU_health = max_su_health;
}

void RandomGenerator::set_MaxSUAttackCapacity(int max_su_attackcapcity)
{
	max_SU_Attack_Capacity = max_su_attackcapcity;
}
