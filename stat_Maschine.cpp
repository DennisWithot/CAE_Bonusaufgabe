#include <iostream>
#include <string>
#include "stat_Maschine.h"

using namespace std;


//Getter:
string stat_Maschine::getstandort_stat_Maschine()
{
	return standort_stat_Maschine;
}


//Setter:
void stat_Maschine::setstandort_stat_Maschine(string standort_stat_Maschine)
{
	this->standort_stat_Maschine = standort_stat_Maschine;
}


//Ausgabe:
void stat_Maschine::print()
{
	cout << "Der Standort der stat_Maschine lautet:" <<standort_stat_Maschine <<endl;
}

//Konstruktor:
Stat_Maschine::Stat_Maschine(string standort_stat_Maschine)
{
	Stat_Maschine::standort_stat_Maschine = standort_stat_Maschine;
}