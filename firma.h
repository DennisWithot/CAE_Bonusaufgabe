#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "mitarbeiter.h"
#include "maschine.h"



using namespace std;

class Maschine;

class Firma{
	private:
	int id_Firma;
	string name_Firma;
	vector<Mitarbeiter> alle_Mitarbeiter;
	vector<Maschine> alle_Maschinen;
	
	
	public:
	//Getter:
	int getid_Firma();
	string getname_Firma();
	vector<Mitarbeiter> get_alle_Mitarbeiter();
	vector<Maschine> get_alle_Maschinen();


	//Setter:
	void setid_Firma(int id_Firma);
	void setname_Firma(string name_Firma);
	void setmitarbeiter(Mitarbeiter mitarbeiter);
    void setmaschine(Maschine maschine);

	//Ausgabe:
	void print();

	//Funktionen:
	void add_Maschine(Maschine maschine);
	void add_Mitarbeiter(int id_Mitarbeiter, string name_Mitarbeiter, string qualifikation_Mitarbeiter);
	void del_Maschine(int id);
	void del_Mitarbeiter(int id);

	Firma(int id_Firma, string name_Firma, vector<Mitarbeiter> alle_Mitarbeiter, vector<Maschine> alle_Maschinen);
	Firma(int id_Firma, string name_Firma);
	Firma();
};