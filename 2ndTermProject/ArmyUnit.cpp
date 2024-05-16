#include "ArmyUnit.h"

ArmyUnit::ArmyUnit(Game* p, double HP, double pow, int ID_, int cap, int _Tj, Unit U)
{
	pGame = p;
	Health = HP;
	Power = pow;
	ID = ID_;
	AttackCap = cap;
	Tj = _Tj;
	Ta = -1;
	Td = 0;
	InitialHealth = Health;
	StepsInUML = 0;
	Type = U;
	IsHealed = 0;
}

void ArmyUnit::Set_Ta(int _Ta)
{
	Ta = _Ta;
}

void ArmyUnit::Set_Td(int _Td)
{
	Td = _Td;
}

void ArmyUnit::Set_StepsInUML(int step)
{
	StepsInUML = step;
}

void ArmyUnit::Set_Healed(bool h)
{
	IsHealed = h;
}

bool ArmyUnit::Get_Healed()
{
	return IsHealed;
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

double ArmyUnit::GetHealth()
{
	return Health;
}

double ArmyUnit::GetInitialH()
{
	return InitialHealth;
}

double ArmyUnit::GetPower()
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

int ArmyUnit::GetStepsInUML()
{
	return StepsInUML;
}

ArmyUnit* ArmyUnit::operator-=(int damage)
{
	Health -= damage;
	return this;
}

void ArmyUnit::SetHealth(double h)
{
	Health = h;
}

void ArmyUnit::PrintUnitInfo()
{
	cout << Health << endl;
}

ostream& operator<<(ostream& COUT, ArmyUnit* Passed_AU)
{
	COUT << Passed_AU->GetID();
	return COUT;
}
