#pragma once
class Game;
class ArmyUnit;

class AlienSoldier :public ArmyUnit
{
public:
	AlienSoldier(Game* p, int HP, int pow, int ID_, int cap, int _Tj, Unit U = ArmyUnit::AS);
	virtual bool Attack();
};

