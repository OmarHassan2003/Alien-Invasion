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

void ArmyUnit::AddEarthUnitToList(EarthArmy* passed_EA)
{
}

void ArmyUnit::AddAlienUnitToList(AlienArmy* passed_EA)
{
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

ArmyUnit* ArmyUnit::operator-=(int damage)
{
	Health -= damage;
	return this;
}

void ArmyUnit::PrintUnitInfo()
{

}
