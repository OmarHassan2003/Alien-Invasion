#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class RandomGenerator
{
protected:
	unsigned short n, ES, ET, EG, AS, AM, AD, Prop, Thr;

	unsigned short min_E_Power, min_E_health, min_E_Attack_Capacity;
	unsigned short max_E_Power, max_E_health, max_E_Attack_Capacity;

	unsigned short min_A_Power, min_A_health, min_A_Attack_Capacity;
	unsigned short max_A_Power, max_A_health, max_A_Attack_Capacity;
public:
	RandomGenerator():n(0)
	{
		cout << "Random Generator Class has been started" << endl;
		Read();
	}
	void Read()
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
	void Print()
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
};

