#include <iostream>
#include <string>


using namespace std;

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