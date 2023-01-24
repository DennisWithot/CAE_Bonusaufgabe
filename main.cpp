#include <iostream>
#include <string>
#include "mitarbeiter.h"
#include "firma.h"

using namespace std;


int main()
{
	/*Firma f1(1, "HALLO");
	Firma f2(2, "POPO");

	f1.print();
	f2.print();

	Mitarbeiter m1(1, "Thomas", "Geselle");
	Mitarbeiter m2(2, "Gisela", "Auszubildener");

	m1.print();
	m2.print();
*/

	//Hauptmenue:

	cout<< "Willkommen im Hauptmenü, bitte wählen Sie eine Aktion aus." <<endl;
	cout<< "0: Element hinzufügen" <<endl;
	cout<< "1: Element löschen" <<endl;
	cout<< "2: Export Textdatei" <<endl;
	cout<< "3: Import Textdatei" <<endl;
	cout<< "4: Übersicht anzeigen" <<endl;

	int input;
	int input2;
	cin>> input;


	if (input == 0)
	{
		cout<< "Was möchten Sie hinzufügen?" <<endl;
		cout<< "0: Maschine" <<endl;
		cout<< "1: Mitarbeiter" <<endl;
		cout<< "2: Wartungsintervall" <<endl;
		cout<< "3: Firma" <<endl;
		cout<< "4: Wartungsplan" <<endl;
		cin>> input2;

		if(input2 == 0)
		{
			cout<< "Nennen Sie die ID der Maschine:";
			cin>> int id_Maschine;
			cout<< "Nennen Sie den Namen der Maschine:";
			cin>> string name_Maschine;
			cout<< "Nennen Sie die Firma der Maschine:";
			cin>> Firma firma;

			Maschine::add_Maschine(id_Maschine, name_Maschine, firma);
		}
		if(input2 == 1)
		{
			cout<< "Nennen Sie die ID des Mitarbeiters:";
			cin>> int id_Mitarbeiter;
			cout<< "Nennen Sie den Namen des Mitarbeiters:";
			cin>> string name_Mitarbeiter;
			cout<< "Nennen Sie die Qualifikation des Mitarbeiters:";
			cin>> string qualifikation_Mitarbeiter;

			Mitarbeiter::add_Mitarbeiter(id_Mitarbeiter, name_Mitarbeiter, qualifikation_Mitarbeiter);
		}
		if(input2 == 2)
		{
			cout<< "Nennen Sie die Länge des Intervalls:";
			cin>> int laenge_Intervall;

		   Intervall::add_Intervall(laenge_Intervall);
		}
		if(input2 == 3)
		{
			cout<< "Nennen Sie die ID der Firma:";
			cin>> int id_Firma;

			cout<< "Nennen Sie den Namen der Firma:";
			cin>> string name_Firma;

			cout<< "Nennen Sie die ID des gewünschten Mitarbeiters:";
			for (Mitarbeiter i: alle_Mitarbeiter)
			{
    			cout << i.getid_Mitarbeiter() << '\t' <<i.getname_Mitarbeiter() << '\t' <<i.getqualifikation_Mitarbeiter() <<endl;
			}
			cin>> int id_Mitarbeiter;

			cout<< "Nennen Sie die ID der gewünschten Maschine:";
			for (Maschine i: alle_Maschinen)
			{
    			cout << i.getid_Maschine() << '\t' <<i.getname_Maschine()<<endl;
			}
			cin>> int id_Maschine;


		   Firma::add_Firma(id_Firma, name_Firma, id_Mitarbeiter, id_Maschine);
		}
		//Platzhalter für Wartungsplan!!
		/*if(input2 == 4)
		{
			cout<< "Nennen Sie die ID der Firma:";
			cin>> int id_Firma;

			cout<< "Nennen Sie den Namen der Firma:";
			cin>> string name_Firma;

			cout<< "Nennen Sie die ID des gewünschten Mitarbeiters:";
			for (Mitarbeiter i: alle_Mitarbeiter)
			{
    			cout << i.getid_Mitarbeiter() << '\t' <<i.getname_Mitarbeiter() << '\t' <<i.getqualifikation_Mitarbeiter() <<endl;
			}
			cin>> int id_Mitarbeiter;

			cout<< "Nennen Sie die ID der gewünschten Maschine:";
			for (Maschine i: alle_Maschinen)
			{
    			cout << i.getid_Maschine() << '\t' <<i.getname_Maschine()<<endl;
			}
			cin>> int id_Maschine;


		   Firma::add_Firma(id_Firma, name_Firma, id_Mitarbeiter, id_Maschine);
		}*/	
	}

	if (input == 1)
	{
		cout<< "Was möchten Sie löschen?" <<endl;
		cout<< "0: Maschine" <<endl;
		cout<< "1: Mitarbeiter" <<endl;
		cout<< "2: Firma" <<endl;
		cout<< "3: Wartungsplan" <<endl;
		cin>> input2;

		if(input2 == 0)
		{
			cout<< "Nennen Sie die ID der zu löschenden Maschine:";
			for (Maschine i: alle_Maschinen)
			{
    			cout << i.getid_Maschine() << '\t' <<i.getname_Maschine() <<endl;
			}
			cin>> int id_Maschine;

			Maschine::del_Maschine(id_Maschine);
		}
		if(input2 == 1)
		{
			cout<< "Nennen Sie die ID des zu löschenden Mitarbeiters:";
			for (Mitarbeiter i: alle_Mitarbeitern)
			{
    			cout << i.getid_Mitarbeiter() << '\t' <<i.getname_Mitarbeiter() <<endl;
			}
			cin>> int id_Mitarbeiter;

			Mitarbeiter::del_Mitarbeiter(id_Mitarbeiter);
		}
		if(input2 == 2)
		{
			cout<< "Nennen Sie die ID der zu löschenden Firma:";
			for (Firma i: alle_Firmen)
			{
    			cout << i.getid_Firma() << '\t' <<i.getname_Firma() <<endl;
			}
			cin>> int id_Firma;

			Firma::del_Firma(id_Firma);
		}
		if(input2 == 3)
		{
			cout<< "Nennen Sie die ID des zu löschenden Wartungsplans:";
			for (Wartungsplan i: alle_Wartungsplaene)
			{
    			cout << i.getid_Wartungsplan() << '\t' <<i.getname_Wartungsplan()<<endl;
			}
			cin>> int id_Wartungsplan;

			Wartungsplan::del_Wartungsplan(id_Wartungsplan);
		}
		
	}

	if (input == 2)
	{
		cout<< "Was möchten Sie exportieren?" <<endl;
		cout<< "0: Alle Maschinen" <<endl;
		cout<< "1: Alle Mitarbeiter" <<endl;
		cout<< "2: Alle Wartungsintervalle" <<endl;
		cout<< "3: Alle Wartungspläne" <<endl;
		cin>> input2;

		if(input2 == 0)
		//Exportieren der Daten in .txt!!
		//define array of strings
		string alle_Maschinen[10] = { "value0", "value1", "value2","value3", "value4", "value5","value6", "value7","value8", "value9" }; //können wir alle_Mitarbeiter direkt nehmen, ist schon ein Vektor!!
		//open file for writing
		ofstream fw("C:\Users\Besitzer\Documents\GitHub\CAE_Bonusaufgabe\\alle_Maschinen.txt", std::ofstream::out);
		//check if file was successfully opened for writing
		if (fw.is_open())
		{
			//store array contents to text file
			for (int i = 0; i < arraySize; i++) 
			{
				fw << alle_Maschinen[i] << "\n";
			}
			fw.close();
		}
		else
		{ 
			cout << "Problem with opening file";
		}
	}
	//close the file after the writing operation is completed
	fw.close();

	if (input == 3)
	{
		//Importieren der Daten aus .txt!!
	}

		if (input == 4)
	{
		//Ausgeben der Übersicht!!
	}