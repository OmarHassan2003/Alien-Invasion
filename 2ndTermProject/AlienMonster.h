#pragma once
class Game;
class ArmyUnit;

class AlienMonster:public ArmyUnit
{
public:
	AlienMonster();
	AlienMonster(Game* p, int HP, int pow, int ID_, int cap, int _Tj);
	virtual bool Attack();
};

