#include "EarthArmy/EarthArmy.h"
#include "AlienArmy/AlienArmy.h"
#include "RandomGenerator/RandomGenerator.h"
#include "Game.h"



int main()
{
	RandomGenerator randGen;
	Game gmain;
	while (gmain.Get_And_Inc_Tj() <= 50)
	{
		gmain.Generate_Earth_Army();
		gmain.Generate_Alien_Army();
		unsigned short randomNumber = randGen.RandGen(0, 100);
		if (randomNumber < 10)
		{
			gmain.process_ES();
		}
		else if (randomNumber < 20)
		{
			gmain.process_ET();
		}
		else if (randomNumber < 30)
		{
			gmain.process_EG();
		}
		else if (randomNumber < 40)
		{

		}
		else if (randomNumber < 50)
		{

		}
		else if (randomNumber < 60)
		{

		}
		gmain.print();
	}
}

