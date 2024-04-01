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
