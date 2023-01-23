#include <iostream>
#include <string>
#include "bew_Maschine.h"

using namespace std;


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
}