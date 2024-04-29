#include "EarthArmy/EarthArmy.h"
#include "AlienArmy/AlienArmy.h"
#include "RandomGenerator/RandomGenerator.h"
#include "Game.h"

int main()
{
	Game gmain;
	bool EndGame = false;
	while (!EndGame)
	{
		gmain.Get_And_Inc_Tj();
		gmain.Generate_Earth_Army();
		gmain.Generate_Alien_Army();
		gmain.Attack();
		gmain.print();
		if(gmain.Get_Tj()>40)
			EndGame = gmain.CheckWhoWins();
	}
}