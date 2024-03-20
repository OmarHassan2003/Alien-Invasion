#pragma once
#include "Game.h"

class ArmyUnit
{
protected:
	enum Unit {
		ES,AS,ET,AM,EG,AD
	};
private:
	Game* pGame;
	int Health;
	int Power;
	int ID;
	int AttackCap;
	Unit Type;
	//Tj,Ta,Td,Df,Dd,Db?? Here or in another class??
	
public:
	ArmyUnit(Game* p, int HP, int pow, int ID_, int cap, Unit U);
	virtual bool Attack() = 0;
	//virtual bool AddUnit() = 0; //
	//virtual bool RemoveUnit() = 0;
	virtual int GetHealth();
	virtual int GetPower();
	virtual int GetID();
	virtual int GetAttackCap();
	virtual Unit GetUnitType(); // Maybe causes a logical error
	ArmyUnit* operator -= (int damage);

	void PrintUnitInfo();
};

