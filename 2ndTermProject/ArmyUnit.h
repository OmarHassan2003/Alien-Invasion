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
private:
	Game* pGame;
	int Health;
	int Power;
	int ID;
	int AttackCap;
	int Tj, Ta, Td;
public:
	ArmyUnit(Game* p, int HP, int pow, int ID_, int cap, int Tj);

	virtual bool Attack(ArmyUnit* AU0 = nullptr,ArmyUnit* AU1 = nullptr) = 0;

	virtual void Set_Ta(int);
	virtual void Set_Td(int);

	virtual void AddEarthUnitToList(EarthArmy* passed_EA) = 0;
	virtual void AddAlienUnitToList(AlienArmy* passed_EA) = 0;

	virtual int Get_Ta();
	virtual int Get_Tj();
	virtual int Get_Td();
	virtual int GetHealth();
	virtual int GetPower();
	virtual int GetID();
	virtual int GetAttackCap();

	void SetHealth(int h);
	friend ostream& operator<<(ostream& COUT, ArmyUnit* Passed_AU);
	void PrintUnitInfo();
};

#endif // !ARMY_UNIT_H_