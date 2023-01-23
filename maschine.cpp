#include <iostream>
#include <string>
#include "maschine.h"

using namespace std;


//Getter:

int Maschine::getid_Maschine()
{
	return id_Maschine;
}
string Maschine::getname_Maschine()
{
	return name_Maschine;
}
Firma Maschine::getfirma()
{
	return firma;
;
}

//Setter:
void Maschine::setid_Maschine(int id_Maschine)
{
	this->id_Maschine = id_Maschine;
}
void Maschine::setname_Maschine(string name_Maschine)
{
	this->name_Maschine = name_Maschine;
}
Firma Maschine::setfirma(string firma)
{
	this->firma = firma;

}
//Ausgabe:
void Maschine::print()
{
	cout << "Die ID der Maschine lautet:" <<id_Maschine <<endl;
	cout << "Der Name der Maschine lautet:" <<name_Maschine <<endl;
	cout << "Die zugehörige Firma lautet:" <<firma <<endl;
}

Maschine::Maschine(int id_Maschine, string name_Maschine, Firma firma)
{
	Maschine::id_Maschine = id_Maschine;
	Maschine::name_Maschine = name_Maschine;
	Maschine::firma = firma;
;
}