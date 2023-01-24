#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "mitarbeiter.h"
#include "maschine.h"


using namespace std;

class Firma{
	private:
	int id_Firma;
	string name_Firma;
	vector<Mitarbeiter> alle_Mitarbeiter;
	vector<Maschine> alle_Maschinen;

	/*std::vector<Mitarbeiter*> alle_mitarbeiter;
	alle_mitarbeiter.append(neuer_mitarbeiter);
	for (int i=0; i<alle_mitarbeiter.size();i++){
		alle_mitarbeiter[i]->getname();
	}*/
    //Maschine maschine;
	
	
	public:
	//Getter:
	int getid_Firma();
	string getname_Firma();
	vector<Mitarbeiter> get_alle_Mitarbeiter();
	vector<Maschine> get_alle_Maschinen();

	/*Mitarbeiter* mitarb = miele.getmitarbeiter();
	name = mitarb->getname_Mitarbeiter();*/
    //Maschine getmaschine();

	//Setter:
	void setid_Firma(int id_Firma);
	void setname_Firma(string name_Firma);
	void setmitarbeiter(Mitarbeiter mitarbeiter);
    //void setmaschine(Maschine maschine);

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