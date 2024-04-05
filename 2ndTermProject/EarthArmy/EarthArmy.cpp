#include "EarthArmy.h"

EarthArmy::EarthArmy()
{
}

bool EarthArmy::AddUnit(Game* pG, char u, int hp, int pow, int id, int cap, int Tj)
{
	if (u == 'S')
	{
		EarthSoldier* EarthS = new EarthSoldier(pG, hp, pow, id, cap, Tj);
		ES.enqueue(EarthS);
		return true;
	}
	if (u == 'T')
	{
		//Tank creation
		return true;
	}
	if (u == 'G')
	{
		//Gunnery creation
		return true;
	}
	return false;
}
