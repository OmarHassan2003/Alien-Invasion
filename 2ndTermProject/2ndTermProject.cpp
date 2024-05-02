#include "EarthArmy/EarthArmy.h"
#include "AlienArmy/AlienArmy.h"
#include "RandomGenerator/RandomGenerator.h"
#include "Game.h"

enum GameMode
{
	ACTIVE_MODE,
	SILENT_MODE
};

istream& operator>>(istream& CIN, GameMode& mode)
{
	int x;
	CIN >> x;
	if (x <= 0)
		mode = ACTIVE_MODE;
	else
		mode = SILENT_MODE;
	return CIN;
}

int main()
{
	Game gmain;
	bool EndGame = false;
	bool SilentMode;
	GameMode gameMode;
	cout << "Which mode you want your motherf*** game be?  0->Active mode  1->Silent Mode" << endl;
	cin >> gameMode;
	if (gameMode == SILENT_MODE)
		cout << "Silent Mode" << endl << "Simulation Starts." << endl;
	while (!EndGame)
	{
		gmain.Get_And_Inc_Tj();
		gmain.Generate_Earth_Army();
		gmain.Generate_Alien_Army();
		gmain.print();
		gmain.Attack();
		if(gameMode == ACTIVE_MODE)
			gmain.print();
		if (gmain.Get_Tj() > 40)
		{
			EndGame = gmain.CheckWhoWins();
			gmain.GenerateOutputFile();
			system("pause");
		}
	}
}