#include "AlienDrone.h"

AlienDrone::AlienDrone(Game* p, int HP, int pow, int ID_, int cap, int Tj, Unit U):
	ArmyUnit(p,HP,pow,ID_,cap,Tj,U)
{

}

void AlienDrone::AddEarthUnitToList(EarthArmy* passed_EA)
{
}

void AlienDrone::AddAlienUnitToList(AlienArmy* passed_AA)
{
	passed_AA->AddInDoubleLinkedQueueQueue(this);
}


bool AlienDrone::Attack()
{
	return false;
}

ostream& operator<<(ostream& COUT, AlienDrone& PAssed_AD)
{
	COUT << PAssed_AD.GetID() << " ";
	return COUT;
	// TODO: insert return statement here
}
