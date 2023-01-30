#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "mitarbeiter.h"


using namespace std;
class Maschine;
class bew_Maschine;
class stat_Maschine;
class Firma
{
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

class Maschine{
	private:
	int id_Maschine;
	string name_Maschine;
	Firma firma;

	
	public:
	//Getter:
	int getid_Maschine();
	string getname_Maschine();
	Firma getfirma();

	//Setter:
	void setid_Maschine(int id_Maschine);
	void setname_Maschine(string name_Maschine);
	void setfirma(Firma firma);

	//Ausgabe:
	void print();

	Maschine(int id_Maschine, string name_Maschine, Firma firma);
	Maschine();
};
/*
class Stat_Maschine : Maschine
{
	private:
	string standort_stat_Maschine;


	
	public:
	//Getter:
	string getstandort_stat_Maschine();


	//Setter:
	void setstandort_stat_Maschine(string standort_stat_Maschine);


	//Ausgabe:
	void print();

	Stat_Maschine(string standort_stat_Maschine);
};

class Bew_Maschine : Maschine
{
	private:
	int gewicht_bew_Maschine;


	
	public:
	//Getter:
	int getgewicht_bew_Maschine();


	//Setter:
	void setid_bew_Maschine(int gewicht_bew_Maschine);


	//Ausgabe:
	void print();

	Bew_Maschine(int gewicht_bew_Maschine);
};
*/