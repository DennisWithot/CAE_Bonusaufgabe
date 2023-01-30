#include <iostream>
#include <string>
#include <vector>

#include "maschfirma.h"


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
void Maschine::setfirma(Firma firma)
{
	this->firma = firma;

}
//Ausgabe:
void Maschine::print()
{
	cout << "Die ID der Maschine lautet:" <<id_Maschine <<endl;
	cout << "Der Name der Maschine lautet:" <<name_Maschine <<endl;
	cout << "Die zugehörige Firma lautet:" <<firma.getname_Firma() <<endl;
}

Maschine::Maschine(int id_Maschine, string name_Maschine, Firma firma)
{
	Maschine::id_Maschine = id_Maschine;
	Maschine::name_Maschine = name_Maschine;
	Maschine::firma = firma;
}

Maschine::Maschine(){}

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
		Mitarbeiter current_Mitarbeiter = alle_Mitarbeiter[i];
		int current_id = current_Mitarbeiter.getid_Mitarbeiter();
		if(current_id == id_Mitarbeiter)
		{
			cout<<"Der Mitarbeiter mit dieser ID besteht bereits."<<endl;
		}
		else
		{
			Mitarbeiter temp_Mitarbeiter = Mitarbeiter(id_Mitarbeiter, name_Mitarbeiter, qualifikation_Mitarbeiter);
			alle_Mitarbeiter.push_back(temp_Mitarbeiter);
		}
	}
}



//Ausgabe:
void Firma::print()
{
	cout << "Die ID der Firma lautet:" <<id_Firma <<endl;
	cout << "Der Name der Firma lautet:" <<name_Firma <<endl;
	//cout << "Der/die Mitarbeiter der Firmas lautet/lauten:" <<mitarbeiter <<endl;
    //cout << "Die Maschine/Maschinen der Firmas lautet/lauten:" <<maschine <<endl;
}

void Firma::add_Maschine(Maschine maschine)
{
	this->alle_Maschinen.push_back(maschine);
}

void Firma::del_Maschine(int id)
{
	for(int i=0; i<alle_Maschinen.size(); i++)
	{
		if(alle_Maschinen[i].getid_Maschine()==id)
		{
			//maschine aus liste loeschen
			alle_Maschinen.erase(alle_Maschinen.begin()+i);
		}
	}
}
void Firma::del_Mitarbeiter(int id)
{
	for(int i=0; i<alle_Mitarbeiter.size(); i++)
	{
		if(alle_Mitarbeiter[i].getid_Mitarbeiter()==id)
		{
			//mitarbeiter aus liste loeschen
			alle_Mitarbeiter.erase(alle_Mitarbeiter.begin()+i);
		}
	}
}

//Konstruktor:
Firma::Firma(int id_Firma, string name_Firma, vector<Mitarbeiter> alle_Mitarbeiter, vector<Maschine> alle_Maschinen)
{
	Firma::id_Firma = id_Firma;
	Firma::name_Firma = name_Firma;
	Firma::alle_Mitarbeiter = alle_Mitarbeiter;
}

//Alternativer Konstruktor
Firma::Firma(int id_Firma, string name_Firma)
{
	Firma::id_Firma = id_Firma;
	Firma::name_Firma = name_Firma;
}

Firma::Firma(){}

/*
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

//Getter:
int bew_Maschine::getgewicht_bew_Maschine()
{
	return gewicht_bew_Maschine;
}


//Setter:
void bew_Maschine::setgewicht_bew_Maschine(int gewicht_bew_Maschine)
{
	this->gewicht_bew_Maschine = gewicht_bew_Maschine;
}


//Ausgabe:
void bew_Maschine::print()
{
	cout << "Das Gewicht der bew_Maschines lautet:" <<gewicht_bew_Maschine <<endl;
}

//Konstruktor:
Bew_Maschine::Bew_Maschine(int gewicht_bew_Maschine)
{
	Bew_Maschine::gewicht_bew_Maschine = gewicht_bew_Maschine;
}*/