
#include "intervall.h"

using namespace std;


//Getter:

int Intervall::getlaenge_Intervall()
{
	return laenge_Intervall;
}


//Setter:
void Intervall::setlaenge_Intervall(int laenge_Intervall)
{
	this->laenge_Intervall = laenge_Intervall;
}


Intervall::Intervall(int laenge_Intervall)
{
	Intervall::laenge_Intervall = laenge_Intervall;

}