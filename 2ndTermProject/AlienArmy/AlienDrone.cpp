#include "AlienDrone.h"

AlienDrone::AlienDrone(Game* p, int HP, int pow, int ID_, int cap, int Tj):
	ArmyUnit(p,HP,pow,ID_,cap,Tj)
{

}

void AlienDrone::AddEarthUnitToList(EarthArmy* passed_EA)
{
}

void AlienDrone::AddAlienUnitToList(AlienArmy* passed_AA)
{
	passed_AA->AddInDoubleLinkedQueueQueue(this);
}

bool AlienDrone::Attack(ArmyUnit* AU0, ArmyUnit* AU1)
{
	if (AU0)
	{
		AU0->SetHealth(AU0->GetHealth() - this->GetAttackCap());
		return true;
	}
	else if (AU1)
	{
		AU1->SetHealth(AU1->GetHealth() - this->GetAttackCap());
		return true;
	}
	else
		return false;
}

ostream& operator<<(ostream& COUT, AlienDrone* PAssed_AD)
{
	COUT << PAssed_AD->GetID() << " ";
	return COUT;
}
