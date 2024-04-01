#pragma once
#include <fstream>
using namespace std;

class RandomGenerator
{
protected:
	unsigned short n, ES, ET, EG, AS, AM, AD, Prop;

	unsigned short min_E_Power, min_E_health, min_E_Attack_Capacity;
	unsigned short max_E_Power, max_E_health, max_E_Attack_Capacity;

	unsigned short min_A_Power, min_A_health, min_A_Attack_Capacity;
	unsigned short max_A_Power, max_A_health, max_A_Attack_Capacity;

public:
	RandomGenerator()
	{
		
	}
	void Read()
	{
		 
	}
};

