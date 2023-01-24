#include <iostream>
#include <string>


using namespace std;

class Stat_Maschine{
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