#include "EarthArmy.h"

EarthArmy::EarthArmy()
{
}

bool EarthArmy::AddUnit(char u, int hp, int pow, int id, int cap, int Tj)
{
	//Game* p;
	if (u == 'S')
	{
		//EarthSoldier* EarthS = new EarthSoldier(p, hp, pow, id, cap, Tj);
		//ES.enqueue(EarthS);
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
