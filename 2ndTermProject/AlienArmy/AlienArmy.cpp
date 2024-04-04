#include "AlienArmy.h"
#include "../Game.h"

AlienArmy::AlienArmy()
{
}

bool AlienArmy::AddUnit(Game*pG, char u, int hp, int pow, int id, int cap, int Tj)
{
	if (u == 'S')
	{
		AlienSoldier* AlienS = new AlienSoldier(pG, hp, pow, id, cap, Tj);
		AS.enqueue(AlienS);
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
