#include "EarthArmy/EarthArmy.h"
#include "AlienArmy/AlienArmy.h"
#include "RandomGenerator/RandomGenerator.h"
#include "Game.h"


int main()
{
	Game gmain;
	gmain.Generate_Earth_Army();
	gmain.Generate_Alien_Army();
}

