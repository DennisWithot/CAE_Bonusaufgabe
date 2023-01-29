#include <iostream>
#include <string>
#include "mitarbeiter.h"
//#include "maschine.h"
//#include "firma.h"
#include "intervall.h"
#include "wartungsplan.h"
#include "maschfirma.h"

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
string Wartungsplan::getnotwendige_Qualifikation()
{
	return notwendige_Qualifikation;
}
Maschine Wartungsplan::getMaschine()
{
	return maschine;
}
Intervall Wartungsplan::getIntervall()
{
	return intervall;
}
Mitarbeiter Wartungsplan::getMitarbeiter()
{
	return mitarbeiter;
}
Firma Wartungsplan::getFirma()
{
	return firma;
}

//Setter:
void Wartungsplan::setid_Wartungsplan(int id_Wartungsplan)
{
	this->id_Wartungsplan = id_Wartungsplan;
}
void Wartungsplan::setname_Wartungsplan(string name_Wartungsplan)
{
	this->name_Wartungsplan = name_Wartungsplan;
}
void Wartungsplan::setnotwendige_Qualifikation(string notwendige_Qualifikation)
{
	this->notwendige_Qualifikation = notwendige_Qualifikation;
}
void Wartungsplan::setMaschine(Maschine maschine)
{
	this->maschine = maschine;
}
void Wartungsplan::setIntervall(Intervall intervall)
{
	this->intervall = intervall;
}
void Wartungsplan::setFirma(Firma firma)
{
	this->firma = firma;
}
void Wartungsplan::setmitarbeiter(Mitarbeiter mitarbeiter)
{
	this->mitarbeiter = mitarbeiter;
}

//Ausgabe: //muss hier eine Ausgabe für zb qualifikation_Mitarbeiter rein ? Oder gibt der das in Mitarbeiter aus ? Ab hier weiter machen!
void Wartungsplan::print()
{
	cout << "Die ID der Wartungsplan lautet:" <<id_Wartungsplan <<endl;
	cout << "Der Name der Wartungsplan lautet:" <<name_Wartungsplan <<endl;
	cout << "Der/die Mitarbeiter der Wartungsplans lautet/lauten:" <<mitarbeiter.getname_Mitarbeiter() <<endl;
    cout << "Die Maschine des Wartungsplans lautet:" << maschine.getname_Maschine() <<endl;
}

//Konstruktor:
Wartungsplan::Wartungsplan(int id_Wartungsplan, string name_Wartungsplan, string notwendige_Qualifikation, Maschine maschine, Intervall intervall, Mitarbeiter mitarbeiter,  Firma firma)
{
	this->id_Wartungsplan = id_Wartungsplan;
	this->name_Wartungsplan = name_Wartungsplan;
	this->notwendige_Qualifikation = notwendige_Qualifikation;
	this->maschine = maschine;
	this->intervall = intervall;
	this->mitarbeiter = mitarbeiter;
	this->firma = firma;
}

Wartungsplan::Wartungsplan(){}