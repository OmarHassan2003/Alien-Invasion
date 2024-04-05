#include "AlienArmy.h"

AlienArmy::AlienArmy()
{
}

bool AlienArmy::AddUnit(char u, int hp, int pow, int id, int cap, int Tj)
{
	//Game* p;
	if (u == 'S')
	{
		//AlienSoldier* AlienS = new AlienSoldier(p, hp, pow, id, cap, Tj);
		//AS.enqueue(AlienS);
		return true;
	}
	if (u == 'M')
	{
		// monster
		return true;
	}
	if (u == 'D')
	{
		// drone.
		return true;
	}
	return false;
}
