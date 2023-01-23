#include <iostream>
#include <string>
#include "mitarbeiter.h"

using namespace std;


//Getter:

int Mitarbeiter::getid_Mitarbeiter()
{
	return id_Mitarbeiter;
}
string Mitarbeiter::getname_Mitarbeiter()
{
	return name_Mitarbeiter;
}
string Mitarbeiter::getqualifikation_Mitarbeiter()
{
	return qualifikation_Mitarbeiter;
}

//Setter:
void Mitarbeiter::setid_Mitarbeiter(int id_Mitarbeiter)
{
	this->id_Mitarbeiter = id_Mitarbeiter;
}
void Mitarbeiter::setname_Mitarbeiter(string name_Mitarbeiter)
{
	this->name_Mitarbeiter = name_Mitarbeiter;
}
void Mitarbeiter::setqualifikation_Mitarbeiter(string qualifikation_Mitarbeiter)
{
	this->qualifikation_Mitarbeiter = qualifikation_Mitarbeiter;
}
//Ausgabe:
void Mitarbeiter::print()
{
	cout << "Die ID des Mitarbeiters lautet:" <<id_Mitarbeiter <<endl;
	cout << "Der Name des Mitarbeiters lautet:" <<name_Mitarbeiter <<endl;
	cout << "Die Qualifikation des Mitarbeiters lautet:" <<qualifikation_Mitarbeiter <<endl;
}

Mitarbeiter::Mitarbeiter(int id_Mitarbeiter, string name_Mitarbeiter, string qualifikation_Mitarbeiter)
{
	Mitarbeiter::id_Mitarbeiter = id_Mitarbeiter;
	Mitarbeiter::name_Mitarbeiter = name_Mitarbeiter;
	Mitarbeiter::qualifikation_Mitarbeiter = qualifikation_Mitarbeiter;
}