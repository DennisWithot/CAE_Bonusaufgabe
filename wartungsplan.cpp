#include <iostream>
#include <string>
#include "mitarbeiter.h"
//#include "maschine.h"
#include "firma.h"
//#include "intervall.h"
#include "wartungsplan.h"

using namespace std;


//Getter:
int Wartungsplan::getid_Wartungsplan()
{
	return id_Wartungsplan;
}
string Wartungsplan::getname_Wartungsplan()
{
	return name_Wartungsplan;
}
string* Wartungsplan::getqualifikation_Mitarbeiter()
{
	return qualifikation_Mitarbeiter;
}
Mitarbeiter Wartungsplan::getmitarbeiter()
{
	return mitarbeiter;
}
//Maschine Wartungsplan::getmaschine()
//{
	//return maschine;
//}
//Firma Wartungsplan::getfirma()
//{
	//return firma;
//}
//Intervall Wartungsplan::getintervall()
//{
	//return intervall;
//}

//Setter:
void Wartungsplan::setid_Wartungsplan(int id_Wartungsplan)
{
	this->id_Wartungsplan = id_Wartungsplan;
}
void Wartungsplan::setname_Wartungsplan(string name_Wartungsplan)
{
	this->name_Wartungsplan = name_Wartungsplan;
}
void Wartungsplan::setqualifikation_Mitarbeiter(string* setqualifikation_Mitarbeiter)
{
	this->qualifikation_Mitarbeiter = qualifikation_Mitarbeiter;
}
void Wartungsplan::setmitarbeiter_Wartungsplan(Mitarbeiter mitarbeiter)
{
	this->mitarbeiter = mitarbeiter;
}

/*void Wartungsplan::setmaschine(Maschine maschine)
{
	this->maschine = maschine;
}
void Wartungsplan::setfirma(Firma* firma)
{
	this->firma = firma;
}
void Wartungsplan::setintervall(Intervall intervall)
{
	this->intervall = intervall;
}*/

//Ausgabe: //muss hier eine Ausgabe für zb qualifikation_Mitarbeiter rein ? Oder gibt der das in Mitarbeiter aus ? Ab hier weiter machen!
void Wartungsplan::print()
{
	cout << "Die ID der Wartungsplan lautet:" <<id_Wartungsplan <<endl;
	cout << "Der Name der Wartungsplan lautet:" <<name_Wartungsplan <<endl;
	cout << "Der/die Mitarbeiter der Wartungsplans lautet/lauten:" <<mitarbeiter <<endl;
    //cout << "Die Maschine/Maschinen der Wartungsplans lautet/lauten:" <<maschine <<endl;
}

//Konstruktor:
Wartungsplan::Wartungsplan(int id_Wartungsplan, string name_Wartungsplan, Mitarbeiter mitarbeiter)//, Maschine maschine)
{
	Wartungsplan::id_Wartungsplan = id_Wartungsplan;
	Wartungsplan::name_Wartungsplan = name_Wartungsplan;
	Wartungsplan::mitarbeiter = mitarbeiter;
    //Wartungsplan::maschine = maschine;
}