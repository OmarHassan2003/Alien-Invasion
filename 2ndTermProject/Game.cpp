#include "Game.h"

Game::Game()
{
	randgenn = new RandomGenerator;
	Tj_value = 0;
	ReadData();
}

void Game::Generate_Earth_Army()
{
	ArmyUnit* AU = nullptr;
	unsigned short x = randgenn->RandGen(1, 100);
	if (x <= randgenn->get_Prop())
	{
		for (unsigned short i = 0; i < randgenn->get_n(); i++)
		{
			AU = randgenn->CreateUnit(Tj_value, this, 'E');
			if(AU)
				EA.AddUnit(AU);
		}
	}
}
void Game::Generate_Alien_Army()
{
	ArmyUnit* AU = nullptr;
	unsigned short x = randgenn->RandGen(1, 100);
	if (x <= randgenn->get_Prop())
	{
		for (unsigned short i = 0; i < randgenn->get_n(); i++)
		{
			AU = randgenn->CreateUnit(Tj_value, this, 'A');
			if(AU)
				AA.AddUnit(AU);
		}
	}
}

unsigned short Game::Get_And_Inc_Tj()
{
	Tj_value++;
	return Tj_value;
}
unsigned short Game::Get_Tj()
{
	return Tj_value;
}

void Game::AddInKilledList(ArmyUnit* passed_AU)
{
	Killed_List.enqueue(passed_AU);
	passed_AU->Set_Td(Get_Tj());
}

bool Game::CheckWhoWins()
{
	if (EA.isCompromised())
	{
		cout << "Alien Army has won the game" << endl;
		return true;
	}
	else if (AA.isCompromised())
	{
		cout << "Earth Army has won the game" << endl;
		return true;
	}
	else
		return false;
}

bool Game::Get_AM(AlienMonster*& AU)
{
	return AA.pick_AM(AU);
}
bool Game::Get_AS(AlienSoldier*& AU)
{
	return AA.pick_AS(AU);
}
bool Game::Get_ES(EarthSoldier*& AU)
{
	return EA.pick_ES(AU);
}
bool Game::Get_EG(EarthGunnery*& AU)
{
	return EA.pick_EG(AU);
}
bool Game::Get_AD(AlienDrone*& AU)
{
	return AA.pick_AD(AU);
}
bool Game::Get_L_AD(AlienDrone*& AU)
{
	return AA.pick_Rear_AD(AU);
}
bool Game::Get_ET(EarthTank*& AU)
{
	return EA.pick_ET(AU);
}
bool Game::GetUML(ArmyUnit* AU, int pri)
{
	return UML.dequeue(AU, pri);
}
int Game::Get_ES_Count()
{
	return EA.ES_Count();
}
int Game::Get_AS_Count()
{
	return AA.AS_Count();
}
// ----- Return back to lists after being attacked. -----
void Game::AddToUML(ArmyUnit* passed_AU, int pri) 
{
	if(passed_AU)
		//pri= -1 if Tank and max health-current health for soldiers 
		if (pri == -1)
			UML.enqueue(passed_AU, -1);
		else
			UML.enqueue(passed_AU, Max_E_HP - passed_AU->GetHealth());
}
void Game::Add_ES(EarthSoldier* AU)
{
	EA.AddInQueue(AU);
}

void Game::Add_AS(AlienSoldier* AU)
{
	AA.AddInQueue(AU);
}
void Game::Add_AD(AlienDrone* AU)
{
	AA.AddInDoubleLinkedQueueQueue(AU);
}

void Game::Add_AD_Front(AlienDrone* AU)
{
	AA.AddInLinkedQueue_Front(AU);
}

void Game::Add_AM(AlienMonster* AU)
{
	AA.AddInAmArray(AU);
}

void Game::Add_ET(EarthTank* AU)
{
	EA.AddInStack(AU);
}

void Game::Add_EG(EarthGunnery* AU)
{
	EA.AddInPriQueue(AU);
}

void Game::Attack()
{
	EA.Attack();
	AA.Attack();
}

void Game::print()
{
	cout << "\nCurrent Time Step:" << Tj_value << endl;
	cout << "============================================ Earth Army Alive Units ==========================================" << endl;
	EA.PrintArmyInfo();
	cout << endl;
	cout << "============================================ Alien Army Alive Units ==========================================" << endl;
	AA.PrintArmyInfo();
	cout << endl;
	cout << "============================================ UML Units ==========================================" << endl;
	cout << UML.GetCount() << " units [ ";
	UML.print();
	cout << "]" << endl;
	cout << "============================================ Killed/Destructed Units ==========================================" << endl;
	cout << Killed_List.GetCount() << " units [ ";
	Killed_List.print();
	cout << "]" << endl;
	cout << "===============================================================================================================" << endl;
}

Game::~Game()
{
	delete randgenn;
	while (!Killed_List.isEmpty())
	{
		ArmyUnit* temp;
		Killed_List.dequeue(temp);
		delete temp;
	}
}

void Game::ReadData()
{
	unsigned short n ,h, ES, ET, EG, AS, AM, AD, Prop, min_E_Power, min_E_health, min_E_Attack_Capacity, max_E_Power,
		max_E_health, max_E_Attack_Capacity, min_A_Power, min_A_health, min_A_Attack_Capacity, max_A_Power,
		max_A_health, max_A_Attack_Capacity;
	ifstream Fin("../test.txt");
	if (Fin.is_open())
	{
		Fin >> n >> h >> ES >> ET >> EG >> AS >> AM >> AD >> Prop;
		/***********************Read Earth Data*************************/
		Fin >> min_E_Power;
		Fin.ignore();

		Fin >> max_E_Power;
		Fin.ignore();

		Fin >> min_E_health;
		Fin.ignore();

		Fin >> max_E_health;
		Max_E_HP = (int) max_E_health;
		Fin.ignore();

		Fin >> min_E_Attack_Capacity;
		Fin.ignore();

		Fin >> max_E_Attack_Capacity;
		Fin.ignore();
		/***********************Read Earth Data*************************/
		/***********************Read ALien Data*************************/
		Fin >> min_A_Power;
		Fin.ignore();

		Fin >> max_A_Power;
		Fin.ignore();

		Fin >> min_A_health;
		Fin.ignore();

		Fin >> max_A_health;
		Fin.ignore();

		Fin >> min_A_Attack_Capacity;
		Fin.ignore();

		Fin >> max_A_Attack_Capacity;
		Fin.ignore();
		/***********************Read ALien Data*************************/
		Fin.close();
		/***********************Create the random generator object*************************/
		randgenn->set_n(n);
		randgenn->set_HU_percent(h);
		randgenn->set_ES(ES);
		randgenn->set_ET(ET);
		randgenn->set_EG(EG);
		randgenn->set_AS(AS);
		randgenn->set_AM(AM);
		randgenn->set_AD(AD);
		randgenn->set_Prop(Prop);
		randgenn->set_MinEpower(min_E_Power);
		randgenn->set_MinEhealth(min_E_health);
		randgenn->set_MinEAttackCapacity(min_E_Attack_Capacity);
		randgenn->set_MaxEpower(max_E_Power);
		randgenn->set_MaxEhealth(max_E_health);
		randgenn->set_MaxEAttackCapacity(max_E_Attack_Capacity);
		randgenn->set_MinApower(min_A_Power);
		randgenn->set_MinAhealth(min_A_health);
		randgenn->set_MinAAttackCapacity(min_A_Attack_Capacity);
		randgenn->set_MaxApower(max_A_Power);
		randgenn->set_MaxAhealth(max_A_health);
		randgenn->set_MaxAAttackCapacity(max_A_Attack_Capacity);
	}
	else
		cout << "File failed" << endl;
}