#include "EarthArmy/EarthArmy.h"
#include "AlienArmy/AlienArmy.h"
#include "RandomGenerator/RandomGenerator.h"
#include "Game.h"

int main()
{
	Game gmain;
	bool EndGame = false,gameMode;
	gameMode = gmain.GameMode();
	if (!gameMode)
		cout << "Silent Mode" << endl << "Simulation Starts." << endl;
	while (!EndGame)
	{
		gmain.Get_And_Inc_Tj();
		gmain.Generate_Earth_Army();
		gmain.Generate_Alien_Army();
		gmain.print();
		gmain.Attack();
		if(gameMode)
			gmain.print();
		if (gmain.Get_Tj() > 40)
		{
			EndGame = gmain.CheckWhoWins();
			gmain.GenerateOutputFile();
			system("pause");
		}
	}
	cout << "Simulation ends, Output file is created" << endl;
}