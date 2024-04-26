#include "ArmyUnit.h"

ArmyUnit::ArmyUnit(Game* p, int HP, int pow, int ID_, int cap, int _Tj)
{
	pGame = p;
	Health = HP;
	Power = pow;
	ID = ID_;
	AttackCap = cap;
	Tj = _Tj;
	Ta = 0;
	Td = 0;
	InitialHealth = Health;
	StepsInUML = 0;
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

int ArmyUnit::GetInitialH()
{
	return InitialHealth;
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

int ArmyUnit::GetStepsInUML()
{
	return StepsInUML;
}

void ArmyUnit::SetHealth(int h)
{
	Health = h;
}

void ArmyUnit::PrintUnitInfo()
{
	cout << Health << endl;
}

ostream& operator<<(ostream& COUT, ArmyUnit* Passed_AU)
{
	COUT << Passed_AU->GetID() << " ";
	return COUT;
}
