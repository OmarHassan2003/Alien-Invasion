#ifndef ARMY_UNIT_H_
#define ARMY_UNIT_H_


class Game;
class EarthArmy;
class AlienArmy;
class Army;

class ArmyUnit
{
protected:
	enum Unit {
		ES, EG, ET, AS, AM, AD
	};
private:
	Game* pGame;
	int Health;
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

	virtual void AddEarthUnitToList(EarthArmy* passed_EA) = 0;
	virtual void AddAlienUnitToList(AlienArmy* passed_EA) = 0;
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

#endif // !ARMY_UNIT_H_