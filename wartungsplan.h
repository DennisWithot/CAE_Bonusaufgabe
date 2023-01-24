#include <iostream>
#include <string>
#include "mitarbeiter.h"
#include "maschine.h"
#include "intervall.h"
#include "firma.h"


using namespace std;

class Wartungsplan{
	private:
	int id_Wartungsplan;
	string name_Wartungsplan;
	string notwendige_Qualifikation;
	Maschine maschine;
	Intervall intervall;
	Mitarbeiter mitarbeiter;
	Firma firma; //Firma der Maschine

	public:
	//Getter:
	int getid_Wartungsplan();
	string getname_Wartungsplan();
    string getnotwendige_Qualifikation();
	Maschine getMaschine();
	Intervall getIntervall();
	Mitarbeiter getMitarbeiter();
	Firma getFirma();


	//Setter:
	void setid_Wartungsplan(int id_Wartungsplan);
	void setname_Wartungsplan(string name_Wartungsplan);
	void setnotwendige_Qualifikation(string notwendige_Qualifikation);
	void setMaschine(Maschine maschine);
	void setIntervall(Intervall intervall);
	void setFirma(Firma firma);
	void setmitarbeiter(Mitarbeiter mitarbeiter);

	//Ausgabe:
	void print();

	Wartungsplan(int id_Wartungsplan, string name_Wartungsplan, string notwendige_Qualifikation, Maschine maschine, Intervall intervall, Mitarbeiter mitarbeiter,  Firma firma);
};