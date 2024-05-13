#ifndef ARMY_UNIT_H_
#define ARMY_UNIT_H_
class Game;
#include <iostream>
using namespace std;

class ArmyUnit
{
public:
	enum Unit {
		ES, EG, ET, EH, AS, AM, AD, SU
	};
protected:
	Game* pGame;
private:
	int Health;
	int InitialHealth;
	int StepsInUML;
	int Power;
	int ID;
	int AttackCap;
	int Tj, Ta, Td;
	Unit Type;
public:
	ArmyUnit(Game* p, int HP, int pow, int ID_, int cap, int Tj, Unit U);

	virtual bool Attack() = 0;

	virtual void Set_Ta(int);
	virtual void Set_Td(int);
	virtual void Set_StepsInUML(int);

	virtual int Get_Ta();
	virtual int Get_Tj();
	virtual int Get_Td();
	virtual int GetHealth();
	virtual int GetInitialH();
	virtual int GetPower();
	virtual int GetID();
	virtual int GetAttackCap();
	virtual int GetStepsInUML();
	virtual Unit GetUnitType(); // Maybe causes a logical error

	ArmyUnit* operator-=(int damage);
	// ++ operator to increase StepsInUML

	void SetHealth(int h);
	friend ostream& operator<<(ostream& COUT, ArmyUnit* Passed_AU);
	void PrintUnitInfo();
};

#endif // !ARMY_UNIT_H_