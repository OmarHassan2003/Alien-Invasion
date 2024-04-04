#pragma once
#include "Game.h"

class ArmyUnit
{	
private:
	Game* pGame;
	int Health;
	int Power;
	int ID;
	int AttackCap;
	int Tj, Ta, Td;
public:
	enum Unit {
		ES, EG, ET, AS, AM, AD
	};
private:
	Unit Type;
public:
	ArmyUnit(Game* p, int HP, int pow, int ID_, int cap, int Tj, Unit U);

	virtual bool Attack() = 0;

	virtual void Set_Ta(int);
	virtual void Set_Td(int);
	ArmyUnit* operator -= (int damage);

	virtual int Get_Ta();
	virtual int Get_Tj();
	virtual int Get_Td();
	virtual int GetHealth();
	virtual int GetPower();
	virtual int GetID();
	virtual int GetAttackCap();
	virtual Unit GetUnitType(); // Maybe causes a logical error

	void PrintUnitInfo();
};

