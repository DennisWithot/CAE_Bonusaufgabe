#include <iostream>
#include <string>


using namespace std;

class Mitarbeiter{
	private:
	int id_Mitarbeiter;
	string name_Mitarbeiter;
	string qualifikation_Mitarbeiter;

	
	public:
	//Getter:
	int getid_Mitarbeiter();
	string getname_Mitarbeiter();
	string getqualifikation_Mitarbeiter();

	//Setter:
	void setid_Mitarbeiter(int id_Mitarbeiter);
	void setname_Mitarbeiter(string name_Mitarbeiter);
	void setqualifikation_Mitarbeiter(string qualifikation_Mitarbeiter);

	//Ausgabe:
	void print();

	Mitarbeiter(int id_Mitarbeiter, string name_Mitarbeiter, string qualifikation_Mitarbeiter);
};