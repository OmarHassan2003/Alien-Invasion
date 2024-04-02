#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
{
	cout << "Random Generator Class has been started" << endl;
	Read();
}

void RandomGenerator::Read()
{
	ifstream Fin("../test.txt");
	if (Fin.is_open())
	{
		Fin >> n >> ES >> ET >> EG >> AS >> AM >> AD >> Prop;
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
		Fin.close();
	}
	else
		cout << "File failed" << endl;
}

inline unsigned short RandomGenerator::RandGen(unsigned short lower_bound, unsigned short upper_bound)
{
	return lower_bound + rand() % (upper_bound - lower_bound + 1);
}

void RandomGenerator::Print()
{
	cout << n << " " << ES << " " << ET << " " << EG << " " << AS << " " << AM << " " << AD << " " << Prop << endl;
	cout << min_E_Power << endl;
	cout << max_E_Power << endl;
	cout << min_E_health << endl;
	cout << max_E_health << endl;
	cout << min_E_Attack_Capacity << endl;
	cout << max_E_Attack_Capacity << endl;

	cout << min_A_Power << endl;
	cout << max_A_Power << endl;
	cout << min_A_health << endl;
	cout << max_A_health << endl;
	cout << min_A_Attack_Capacity << endl;
	cout << max_A_Attack_Capacity << endl;
}
