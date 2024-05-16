#include "Game.h"


Game::Game()
{
	randgenn = new RandomGenerator;
	EA = new EarthArmy;
	AA = new AlienArmy;
	Allies = new AlliedArmy;
	EA->SetRandGen(randgenn);
	Tj_value = 1;
	gameMode = false;
}

void Game::IncInfectedES()
{
	EA->IncInfectedES();
}

void Game::Battle()
{
	ReadData();
	bool End = false;
	gameMode = GameMode();
	if (!gameMode)
		cout << "Silent Mode" << endl << "Simulation Starts." << endl;
	while(!End)
	{
		if (gameMode)
				cout << "\nCurrent Time Step:" << Tj_value << endl;
		randgenn->AddUnits(this, Tj_value);
		UpdateUML();
		if (gameMode)
		{
			double tot_count = EA->ES_Count();
			double infected_count = EA->ES_Infected_Count();
			if (tot_count == 0)
			{
				cout << "Current Infected %: No ES Soldiers" << endl;
			}
			else
			{
				double inf_percent = (infected_count / tot_count) * 100;
				cout << "Current Infected %:" << inf_percent << "%" << endl;
			}
			printArmies();
			cout << "============================================ Units Fighting at the current step ============================================" << endl;
		}
		SU_Withdrawal();
		End = Attack();
		Allies->Attack();
		Get_And_Inc_Tj();
		if (gameMode)
		{
			printUMLQueue();
			printKilledList();
		}
		if (Get_Tj() > 40)
		{
			if (CheckWhoWins())
			{
				End = true;
				continue;
			}
			else if (End)
			{
				cout << "War ended with a tie." << endl;
				EA->SetWon(false);
				AA->SetWon(false);
			}
		}
		else
			End = false;
		if(gameMode)
		{
			/*cout << "Press Any key to move to the next timestep" << endl;
			std::cin.get();*/
		}
	}//wait for a click.
	GenerateOutputFile();
	cout << "Simulation ends, Output file is created" << endl;
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

void Game::UpdateUML()
{
	priQueue<ArmyUnit*> tempES;
	Queue<ArmyUnit*> tempET;
	ArmyUnit* AU;
	int x;
	while (ES_UML.dequeue(AU, x))
	{
		AU->Set_StepsInUML(1 + AU->GetStepsInUML());
		if (AU->GetStepsInUML() > 10)
			AddInKilledList(AU);
		else
			tempES.enqueue(AU, x);
	}
	while (tempES.dequeue(AU, x))
		ES_UML.enqueue(AU, x);
	while (ET_UML.dequeue(AU))
	{
		AU->Set_StepsInUML(1 + AU->GetStepsInUML());
		if (AU->GetStepsInUML() > 10)
			AddInKilledList(AU);
		else
			tempET.enqueue(AU);
	}
	while (tempET.dequeue(AU))
		ET_UML.enqueue(AU);
}

void Game::AddInKilledList(ArmyUnit* passed_AU)
{
	Killed_List.enqueue(passed_AU);
	passed_AU->Set_Td(Get_Tj());
}

bool Game::CheckWhoWins()
{
	if (EA->isCompromised())
	{
		if(gameMode)
			cout << "Alien Army has won the game." << endl;
		AA->SetWon(true);
		return true;
	}
	else if (AA->isCompromised())
	{
		if(gameMode)
			cout << "Earth Army has won the game." << endl;
		EA->SetWon(true);
		return true;
	}
	return false;
}

bool Game::Get_AM(AlienMonster*& AU)
{
	return AA->pick_AM(AU);
}
bool Game::Get_AS(AlienSoldier*& AU)
{
	return AA->pick_AS(AU);
}
bool Game::Get_ES(EarthSoldier*& AU)
{
	return EA->pick_ES(AU);
}
bool Game::Get_EG(EarthGunnery*& AU)
{
	return EA->pick_EG(AU);
}
bool Game::Get_AD(AlienDrone*& AU)
{
	return AA->pick_AD(AU);
}
bool Game::Get_SU(SaverUnit*& AU)
{
	return Allies->pick_SU(AU);
}
EarthArmy* Game::getEA_ptr()
{
	return EA;
}
AlienArmy* Game::getAA_ptr()
{
	return AA;
}
AlliedArmy* Game::getAllies_ptr()
{
	return Allies;
}
bool Game::Get_L_AD(AlienDrone*& AU)
{
	return AA->pick_Rear_AD(AU);
}
bool Game::Get_ET(EarthTank*& AU)
{
	return EA->pick_ET(AU);
}
bool Game::Get_ES_UML(ArmyUnit*& AU)
{
	int pri;
	return ES_UML.dequeue(AU, pri);
}
bool Game::Get_ET_UML(ArmyUnit*& AU)
{
	return ET_UML.dequeue(AU);
}
bool Game::Get_GameMode() const
{
	return gameMode;
}
int Game::Get_Count(ArmyUnit::Unit U)
{
	if (U == ArmyUnit::ES)
		return EA->ES_Count();
	else if (U == ArmyUnit::ET)
		return EA->ET_Count();
	else if (U == ArmyUnit::EG)
		return EA->EG_Count();
	else if (U == ArmyUnit::EH)
		return EA->EH_Count();

	else if (U == ArmyUnit::AS)
		return AA->AS_Count();
	else if (U == ArmyUnit::AD)
		return AA->AD_Count();
	else if (U == ArmyUnit::AM)
		return AA->AM_Count();
}

int Game::countDestructed(ArmyUnit::Unit U)
{
	int count = 0;
	Queue<ArmyUnit*> templist;
	ArmyUnit* temp;
	while (Killed_List.dequeue(temp))
	{
		if (temp->GetUnitType() == U)
			count++;
		templist.enqueue(temp);
	}
	while (templist.dequeue(temp))
		Killed_List.enqueue(temp);
	return count;
}

// ----- Return back to lists after being attacked. -----
void Game::AddToESUML(ArmyUnit* passed_AU) 
{
	ES_UML.enqueue(passed_AU, - passed_AU->GetHealth());
}
void Game::AddToETUML(ArmyUnit* passed_AU)
{
	ET_UML.enqueue(passed_AU);
}
void Game::Add_ES(EarthSoldier* AU)
{
	EA->AddInQueue(AU);
}

void Game::Add_AS(AlienSoldier* AU)
{
	AA->AddInQueue(AU);
}
void Game::Add_SU(SaverUnit* SU)
{
	Allies->AddInQueue(SU);
}
void Game::Add_AD(AlienDrone* AU)
{
	AA->AddInDoubleLinkedQueueQueue(AU);
}

void Game::Add_AD_Front(AlienDrone* AU)
{
	AA->AddInLinkedQueue_Front(AU);
}

void Game::Add_AM(AlienMonster* AU)
{
	AA->AddInAmArray(AU);
}

void Game::Add_ET(EarthTank* AU)
{
	EA->AddInStack(AU);
}

void Game::Add_EG(EarthGunnery* AU)
{
	EA->AddInPriQueue(AU);
}

bool Game::Attack()
{
	return !(EA->Attack() | AA->Attack());
}

bool Game::WillInfect()
{
	int y = randgenn->RandGen(1, 100);
	if (y <= randgenn->get_InfectionProbability())
	{
		return true;
	}
	else return false;
}

void Game::SU_Withdrawal()
{
	if (EA->ES_Infected_Count() == 0 && Allies->SU_Count() != 0)
	{
		Allies->withdraw_SU(this);
	}
}



void Game::printArmies()
{
	cout << "============================================ Earth Army Alive Units ==========================================" << endl;
	EA->PrintArmyInfo();
	cout << endl;
	cout << "============================================ Alien Army Alive Units ==========================================" << endl;
	AA->PrintArmyInfo();
	cout << endl;
	cout << "============================================ Allied Army Alive Units ==========================================" << endl;
	Allies->PrintArmyInfo();
	cout << endl;
}

void Game::printUMLQueue()
{
	cout << "============================================ UML Units ==========================================" << endl;
	cout << ES_UML.GetCount() << " units ";
	ES_UML.print();
	cout << endl;
	cout << ET_UML.GetCount() << " units ";
	ET_UML.print();
	cout << endl;
}

void Game::printKilledList()
{
	cout << "============================================ Killed/Destructed Units ==========================================" << endl;
	cout << Killed_List.GetCount() << " units ";
	Killed_List.print();
	cout << endl;
	cout << "===============================================================================================================" << endl;
}

void Game::GenerateOutputFile()
{
	ofstream Fout("output.txt");
	if (!Fout.is_open())
		cout << "An Error Has Happened During Opening Text File" << endl;
	else
	{
		int Unit_Td;
		unsigned int E_Sum_Unit_Df = 0, E_Sum_Unit_Dd = 0, E_Sum_Unit_Db = 0, E_counter = 0;
		unsigned int A_Sum_Unit_Df = 0, A_Sum_Unit_Dd = 0, A_Sum_Unit_Db = 0, A_counter = 0;

		unsigned int Total_ES = EA->Total_ES_Count(), Total_EG = EA->Total_EG_Count(), Total_ET = EA->Total_ET_Count(), Total_EH = EA->Total_EH_Count();
		unsigned int Total_AS = AA->Total_AS_Count(), Total_AM = AA->Total_AM_Count(), Total_AD = AA->Total_AD_Count();

		unsigned int ES_Alive = EA->ES_Count(), EG_Alive = EA->EG_Count(), ET_ALive = EA->ET_Count(), EH_Alive = EA->EH_Count();
		unsigned int AS_Alive = AA->AS_Count(), AM_Alive = AA->AM_Count(), AD_Alive = AA->AD_Count();

		unsigned int ES_Destructed = countDestructed(ArmyUnit::ES), EG_Destructed = countDestructed(ArmyUnit::EG), ET_Destructed = countDestructed(ArmyUnit::ET), EH_Destructed = countDestructed(ArmyUnit::EH);
		unsigned int AS_Destructed = countDestructed(ArmyUnit::AS), AM_Destructed = countDestructed(ArmyUnit::AM), AD_Destructed = countDestructed(ArmyUnit::AD);

		unsigned int Total_ES_Infected = EA->GetTotal_Infected();
		unsigned short Total_H = EA->Total_HealedCount();

		priQueue<ArmyUnit*> temp_pri;
		Stack<ArmyUnit*> temp_stack;
		ArmyUnit* temp;
		Fout << "Td  " << "  ID  " << "  Tj  " << "  Df  " << "  Dd  " << "  Db" << endl << endl;
		while (!Killed_List.isEmpty())
		{
			Killed_List.dequeue(temp);
			temp_pri.enqueue(temp, temp->Get_Td());
			if (temp->GetID() < 1000)
			{
				E_counter++;
				E_Sum_Unit_Df += temp->Get_Ta() - temp->Get_Tj();
				E_Sum_Unit_Dd += temp->Get_Td() - temp->Get_Ta();
				E_Sum_Unit_Db += temp->Get_Td() - temp->Get_Tj();
			}
			else
			{
				A_counter++;
				A_Sum_Unit_Df += temp->Get_Ta() - temp->Get_Tj();
				A_Sum_Unit_Dd += temp->Get_Td() - temp->Get_Ta();
				A_Sum_Unit_Db += temp->Get_Td() - temp->Get_Tj();
			}
		}
		while (!temp_pri.isEmpty())
		{
			temp_pri.dequeue(temp, Unit_Td);
			temp_stack.push(temp);
		}
		while (!temp_stack.isEmpty())
		{
			temp_stack.pop(temp);
			Fout << temp->Get_Td();
			if (temp->Get_Td() < 10)
				Fout << "     ";
			else if (temp->Get_Td() < 100)
				Fout << "    ";
			else if (temp->Get_Td() < 1000)
				Fout << "   ";
			else
				Fout << "  ";

			Fout << temp->GetID();
			if (temp->GetID() < 10)
				Fout << "     ";
			else if (temp->GetID() < 100)
				Fout << "    ";
			else if (temp->GetID() < 1000)
				Fout << "   ";
			else
				Fout << "  ";

			Fout << temp->Get_Tj();
			if (temp->Get_Tj() < 10)
				Fout << "     ";
			else if (temp->Get_Tj() < 100)
				Fout << "    ";
			else if (temp->Get_Tj() < 1000)
				Fout << "   ";
			else
				Fout << "  ";

			Fout << temp->Get_Ta() - temp->Get_Tj();
			if (temp->Get_Ta() - temp->Get_Tj() < 10)
				Fout << "     ";
			else if (temp->Get_Ta() - temp->Get_Tj() < 100)
				Fout << "    ";
			else if (temp->Get_Ta() - temp->Get_Tj() < 1000)
				Fout << "   ";
			else
				Fout << "  ";

			Fout << temp->Get_Td() - temp->Get_Ta();
			if (temp->Get_Td() - temp->Get_Ta() < 10)
				Fout << "     ";
			else if (temp->Get_Td() - temp->Get_Ta() < 100)
				Fout << "    ";
			else if (temp->Get_Td() - temp->Get_Ta() < 1000)
				Fout << "   ";
			else
				Fout << "  ";

			Fout << temp->Get_Td() - temp->Get_Tj() << endl;
		}
		Fout << "\n\nFor Earth Army ->\n";
		Fout << "Total Earth Soldier = " << Total_ES << endl;
		Fout << "Total Infected Earth Soldier %= " << float(Total_ES_Infected) * 100 / Total_ES << endl;
		Fout << "Total Earth Gunnery = " << Total_EG << endl;
		Fout << "Total Earth Tank = " << Total_ET << endl;
		Fout << "Total Earth Healing Unit = " << Total_EH << endl;
		Fout << "Percentage of units healed successfully = " << float(Total_H) * 100 / (Total_ES + Total_EG + Total_ET) << endl;

		Fout << "Destructed Earth Soldier Percentage = " << float(ES_Destructed) * 100 / Total_ES << endl;
		Fout << "Destructed Earth Gunnery Percentage = " << float(EG_Destructed) * 100 / Total_EG << endl;
		Fout << "Destructed Earth Tank Percentage = " << float(ET_Destructed) * 100 / Total_ET << endl;
		Fout << "Destructed Earth Healing Unit Percentage = " << float(EH_Destructed) * 100 / Total_EH << endl;

		Fout << "Total Destructed Earth Units Percentage = " << float(ES_Destructed + EG_Destructed + ET_Destructed + EH_Destructed) * 100 / EA->Total_EarthUnits_Count() << endl;

		Fout << "Average of Df = " << float(E_Sum_Unit_Df) / float(E_counter) << endl;
		Fout << "Average of Dd = " << float(E_Sum_Unit_Dd) / float(E_counter) << endl;
		Fout << "Average of Db = " << float(E_Sum_Unit_Db) / float(E_counter) << endl;
		Fout << "Df/Db% = " << float(E_Sum_Unit_Df) * 100 / float(E_Sum_Unit_Db) << "%" << endl;
		Fout << "Dd/Db% = " << float(E_Sum_Unit_Dd) * 100 / float(E_Sum_Unit_Db) << "%" << endl;

		Fout << "\n\nFor Alien Army ->\n";
		Fout << "Total Alien Soldier = " << Total_AS << endl;
		Fout << "Total Alien Monster = " << Total_AM << endl;
		Fout << "Total Alien Drone = " << Total_AD << endl;

		Fout << "Destructed Alien Soldier Percentage = " << float(AS_Destructed) * 100 / Total_AS << endl;
		Fout << "Destructed Alien Monster Percentage = " << float(AM_Destructed) * 100 / Total_AM << endl;
		Fout << "Destructed Alien Drone Percentage = " << float(AD_Destructed) * 100 / Total_AD << endl;

		Fout << "Total Destructed Alien Units Percentage = " << float(AS_Destructed + AM_Destructed + AD_Destructed) * 100 / AA->Total_AlienUnits_Count() << endl;

		Fout << "Average of Df = " << float(A_Sum_Unit_Df) / float(A_counter) << endl;
		Fout << "Average of Dd = " << float(A_Sum_Unit_Dd) / float(A_counter) << endl;
		Fout << "Average of Db = " << float(A_Sum_Unit_Db) / float(A_counter) << endl;
		Fout << "Df/Db% = " << float(A_Sum_Unit_Df) * 100 / float(A_Sum_Unit_Db) << "%" << endl;
		Fout << "Dd/Db% = " << float(A_Sum_Unit_Dd) * 100 / float(A_Sum_Unit_Db) << "%" << endl;

		if (!EA->GetWon() && !AA->GetWon())
			Fout << "War ended with a tie.";
		else if (EA->GetWon())
			Fout << "Earth Army has won the game.";
		else
			Fout << "Alien Army has won the game.";

		Fout.close();
	}
}


Game::~Game()
{
	delete randgenn;
	delete EA;
	delete AA;
	delete Allies;
	ArmyUnit* au;
	int x;
	while (Killed_List.dequeue(au))
		delete au;
	while (ES_UML.dequeue(au, x))
		delete au;
	while (ET_UML.dequeue(au))
		delete au;

	au = nullptr;
}

void Game::ReadData()
{
	unsigned short n, h, ES, ET, EG, AS, AM, AD, Prop, min_E_Power, min_E_health, min_E_Attack_Capacity, max_E_Power,
		max_E_health, max_E_Attack_Capacity, min_A_Power, min_A_health, min_A_Attack_Capacity, max_A_Power,
		max_A_health, max_A_Attack_Capacity, InfectionProbaility, Threshold, min_SU_Power, min_SU_health, min_SU_Attack_Capacity, max_SU_Power,
		max_SU_health, max_SU_Attack_Capacity;
	ifstream Fin("../test.txt");
	if (Fin.is_open())
	{
		Fin >> n >> h >> ES >> ET >> EG >> AS >> AM >> AD >> Prop >> Threshold >> InfectionProbaility;
		/***********************Read Earth Data*************************/
		Fin >> min_E_Power;
		Fin.ignore();

		Fin >> max_E_Power;
		Fin.ignore();

		Fin >> min_E_health;
		Fin.ignore();

		Fin >> max_E_health;
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
		/***********************Read Saver Unit Data*************************/
		Fin >> min_SU_Power;
		Fin.ignore();

		Fin >> max_SU_Power;
		Fin.ignore();

		Fin >> min_SU_health;
		Fin.ignore();

		Fin >> max_SU_health;
		Fin.ignore();

		Fin >> min_SU_Attack_Capacity;
		Fin.ignore();

		Fin >> max_SU_Attack_Capacity;
		Fin.ignore();
		/***********************Read Saver Unit Data*************************/
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
		randgenn->set_InfectionProbaility(InfectionProbaility);
		randgenn->set_Threshold(Threshold);
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
		randgenn->set_MinSUpower(min_SU_Power);
		randgenn->set_MinSUhealth(min_SU_health);
		randgenn->set_MinSUAttackCapacity(min_SU_Attack_Capacity);
		randgenn->set_MaxSUpower(max_SU_Power);
		randgenn->set_MaxSUhealth(max_SU_health);
		randgenn->set_MaxSUAttackCapacity(max_SU_Attack_Capacity);
	}
	else
		cout << "File failed" << endl;
}

bool Game::GameMode()
{
	int x;
	cout << "Which mode you want your game be in?  0->Active mode  1->Silent Mode" << endl;
	cin >> x;
	if (x <= 0)
		return true;
	else
		return false;
	delete EA;
	delete AA;
}
