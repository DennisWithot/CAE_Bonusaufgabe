#include <iostream>
#include <string>
#include <vector>
#include "mitarbeiter.h"
#include "maschine.h"
#include "firma.h"

using namespace std;


//Getter:
int Firma::getid_Firma()
{
	return id_Firma;
}
string Firma::getname_Firma()
{
	return name_Firma;
}
vector<Mitarbeiter> Firma::get_alle_Mitarbeiter()
{
	return this->alle_Mitarbeiter;
}
vector<Maschine> Firma::get_alle_Maschinen()
{
	return this->alle_Maschinen;
}

//Setter:
void Firma::setid_Firma(int id_Firma)
{
	this->id_Firma = id_Firma;
}
void Firma::setname_Firma(string name_Firma)
{
	this->name_Firma = name_Firma;
}


//Methoden:
void Firma::add_Mitarbeiter(int id_Mitarbeiter, string name_Mitarbeiter, string qualifikation_Mitarbeiter)
{
	for (int i=0; i<alle_Mitarbeiter.size();i++)
	{
		Mitarbeiter current_Mitarbeiter = vector[i];
		int current_id = current_Mitarbeiter.getID();
		if(current_id == id_Mitarbeiter)
		{
			cout<<"Der Mitarbeiter mit dieser ID besteht bereits."<<endl;
		}
		else
		{
			alle_Mitarbeiter.append(new Mitarbeiter(id_Mitarbeiter, name_Mitarbeiter, qualifikation_Mitarbeiter));
		}
	}
}


/*void Firma::setmaschine(Maschine maschine)
{
	this->maschine = maschine;
}*/

//Ausgabe:
void Firma::print()
{
	cout << "Die ID der Firma lautet:" <<id_Firma <<endl;
	cout << "Der Name der Firma lautet:" <<name_Firma <<endl;
	cout << "Der/die Mitarbeiter der Firmas lautet/lauten:" <<mitarbeiter <<endl;
    //cout << "Die Maschine/Maschinen der Firmas lautet/lauten:" <<maschine <<endl;
}

//Konstruktor:
Firma::Firma(int id_Firma, string name_Firma, vector<Mitarbeiter> alle_Mitarbeiter, vector<Maschine> alle_Maschinen)
{
	Firma::id_Firma = id_Firma;
	Firma::name_Firma = name_Firma;
	Firma::mitarbeiter = mitarbeiter;
}