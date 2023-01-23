#include <iostream>
#include <string>
#include "mitarbeiter.h"
#include "firma.h"

using namespace std;


int main()
{
    Firma f1(1, "HALLO");
    Firma f2(2, "POPO");

    f1.print();
    f2.print();

    Mitarbeiter m1(1, "Thomas", "Geselle");
    Mitarbeiter m2(2, "Gisela", "Auszubildener");

    m1.print();
    m2.print();

}