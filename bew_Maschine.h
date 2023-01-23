#include <iostream>
#include <string>


using namespace std;

class Bew_Maschine{
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