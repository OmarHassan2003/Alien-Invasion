#include "AlienDrone.h"

AlienDrone::AlienDrone(Game* p, int HP, int pow, int ID_, int cap, int Tj, Unit U):
	ArmyUnit(p,HP,pow,ID_,cap,Tj,U)
{

}

void AlienDrone::AddAlienUnitToList(AlienArmy* passed_EA)
{
}


bool AlienDrone::Attack()
{
	return false;
}
