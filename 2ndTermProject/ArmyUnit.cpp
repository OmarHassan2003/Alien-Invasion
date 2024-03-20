#include "ArmyUnit.h"

ArmyUnit::ArmyUnit(Game* p, int HP, int pow, int ID_, int cap, Unit U)
{
	pGame = p;
	Health = HP;
	Power = pow;
	ID = ID_;
	AttackCap = cap;
	Type = U;
}

int ArmyUnit::GetHealth()
{
	return Health;
}

int ArmyUnit::GetPower()
{
	return Power;
}

int ArmyUnit::GetID()
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
