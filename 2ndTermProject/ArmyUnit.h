#ifndef ARMY_UNIT_H_
#define ARMY_UNIT_H_
class Game;
class EarthArmy;
class AlienArmy;
class Army;
#include <iostream>
using namespace std;

class ArmyUnit
{
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
public:
	ArmyUnit(Game* p, int HP, int pow, int ID_, int cap, int Tj);

	virtual bool Attack() = 0;

	virtual void Set_Ta(int);
	virtual void Set_Td(int);
	virtual void Set_StepsInUML(int);

	virtual void AddEarthUnitToList(EarthArmy* passed_EA) = 0;
	virtual void AddAlienUnitToList(AlienArmy* passed_EA) = 0;

	virtual int Get_Ta();
	virtual int Get_Tj();
	virtual int Get_Td();
	virtual int GetHealth();
	virtual int GetInitialH();
	virtual int GetPower();
	virtual int GetID();
	virtual int GetAttackCap();
	virtual int GetStepsInUML();
	
	ArmyUnit* operator-=(int damage);
	// ++ operator to increase StepsInUML

	void SetHealth(int h);
	friend ostream& operator<<(ostream& COUT, ArmyUnit* Passed_AU);
	void PrintUnitInfo();
};

#endif // !ARMY_UNIT_H_