#pragma once

class Game;
class ArmyUnit;

class EarthTank:public ArmyUnit
{
public:
	EarthTank(Game* p, int HP, int pow, int ID_, int cap, int _Tj);
	virtual bool Attack();
};

