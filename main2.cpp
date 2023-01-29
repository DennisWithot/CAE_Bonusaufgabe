#include <fstream>
#include <iostream>
using namespace std;
int main()
{
ofstream Ausgabe;
Ausgabe.open("data.txt");
if(Ausgabe)
{
Ausgabe << "Hallo Welt!" << endl;
float pi = 3.14f;
Ausgabe << "pi = " << pi << endl;
}
Ausgabe.close();
}