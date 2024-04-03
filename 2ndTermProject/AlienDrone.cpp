#include "AlienDrone.h"

AlienDrone::AlienDrone(Game* p, int HP, int pow, int ID_, int cap, int Tj, Unit U):
	ArmyUnit(p,HP,pow,ID_,cap,Tj,U)
{

}

bool AlienDrone::Attack()
{
	return false;
}
