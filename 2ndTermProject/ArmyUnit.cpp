#include "ArmyUnit.h"


ArmyUnit::ArmyUnit(Game* p, int HP, int pow, int ID_, int cap, int Tj, Unit U)
{
	pGame = p;
	Health = HP;
	Power = pow;
	ID = ID_;
	AttackCap = cap;
	Type = U;
	Tj = Tj;
}

void ArmyUnit::Set_Ta(int _Ta)
{
	Ta = _Ta;
}

void ArmyUnit::Set_Td(int _Td)
{
	Td = _Td;
}

int ArmyUnit::Get_Ta()
{
	return Ta;
}

int ArmyUnit::Get_Tj()
{
	return Tj;
}

int ArmyUnit::Get_Td()
{
	return Td;
}

int ArmyUnit::GetHealth()
{
	return Health;
}

int ArmyUnit::GetPower()
{
	return Power;
}

int ArmyUnit::GetID() // delete if just needed in printing.
{
	return ID;
}

int ArmyUnit::GetAttackCap()
{
	return AttackCap;
}

ArmyUnit::Unit ArmyUnit::GetUnitType()
{
	return Type;
}

void ArmyUnit::SetHealth(int h)
{
	Health = h;
}

void ArmyUnit::PrintUnitInfo()
{
	cout << Health << endl;
}

ostream& operator<<(ostream& COUT, ArmyUnit& Passed_AU)
{
	COUT << Passed_AU.GetID() << " ";
	return COUT;
}
