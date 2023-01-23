#include <iostream>
#include <string>
#include "mitarbeiter.h"
//#include "maschine.h"
//#include "intervall.h"
//#include "firma.h"


using namespace std;

class Wartungsplan{
	private:
	int id_Wartungsplan;
	string name_Wartungsplan;
    string* qualifikation_Mitarbeiter;
	Mitarbeiter* mitarbeiter; 
    //Maschine* maschine;
    //Firma* firma;
    //Intervall* intervall;

	
	public:
	//Getter:
	int getid_Wartungsplan();
	string getname_Wartungsplan();
    string* getqualifikation_Mitarbeiter;
	Mitarbeiter* getmitarbeiter();
    //Maschine* getmaschine();
    //Firma* getfirma;
    //Intervall* getintervall;

	//Setter:
	void setid_Wartungsplan(int id_Wartungsplan);
	void setname_Wartungsplan(string name_Wartungsplan);
    void setqualifikation_Mitarbeiter(string* qualifikation_Mitarbeiter);
	void setmitarbeiter(Mitarbeiter* mitarbeiter);
    //void setmaschine(Maschine* maschine);
    //void setfirma(Firma* firma);
    //void setintervall(Intervall* intervall);

	//Ausgabe:
	void print();

	Wartungsplan(int id_Wartungsplan, string name_Wartungsplan,string* qualifikation_Mitarbeiter, Mitarbeiter mitarbeiter, Maschine maschine, Firma* firma, Intervall* intervall);
};