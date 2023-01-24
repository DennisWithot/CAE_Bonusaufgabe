#include <iostream>
#include <string>
#include "mitarbeiter.h"
#include "firma.h"
#include "intervall.h"
#include "wartungsplan.h"

using namespace std;


vector<Mitarbeiter> alle_Mitarbeiter;
vector<Intervall> alle_Intervalle;
vector<Wartungsplan> alle_Wartungsplaene;
vector<Firma> alle_Firmen;
bool run;

int loop()
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

	

	int id_Maschine;
	int id_Mitarbeiter;
	int laenge_Intervall;
	int id_Firma;
	string name_Mitarbeiter;
	string name_Maschine;
	string qualifikation_Mitarbeiter;
	string name_Firma;
	Firma firma;

	if (input == 0)
	{
		cout<< "Was möchten Sie hinzufügen?" <<endl;
		cout<< "0: Maschine" <<endl;
		cout<< "1: Mitarbeiter" <<endl;
		cout<< "2: Wartungsintervall" <<endl;
		cout<< "3: Firma" <<endl;
		cout<< "4: Wartungsplan" <<endl;
		cin>> input2;

		if(input2 == 0) //Maschine hinzufuegen
		{
			cout<< "Nennen Sie die ID der Maschine:";
			cin>> id_Maschine;
			cout<< "Nennen Sie den Namen der Maschine:";
			cin>> name_Maschine;
			cout<< "Nennen Sie die ID der gewünschten Firma:";
			for (Firma i: alle_Firmen)
			{
    			cout << i.getid_Firma() << '\t' <<i.getname_Firma() <<endl;
			}
			cin>> id_Firma;
			for (Firma i: alle_Firmen)
			{
				if(i.getid_Firma()==id_Firma)
				{
					firma = i;
				}
				else
				{
					//Firma not found, return -1;
					return -1;
				}
			}

			Maschine tempMaschine = Maschine(id_Maschine, name_Maschine, firma);
			firma.add_Maschine(tempMaschine);
		}
		if(input2 == 1) //Mitarbeiter hinzufuegen
		{
			cout<< "Nennen Sie die ID des Mitarbeiters:";
			cin>> id_Mitarbeiter;
			cout<< "Nennen Sie den Namen des Mitarbeiters:";
			cin>> name_Mitarbeiter;
			cout<< "Nennen Sie die Qualifikation des Mitarbeiters:";
			cin>> qualifikation_Mitarbeiter;
			Mitarbeiter mitarbeiter = Mitarbeiter(id_Mitarbeiter, name_Mitarbeiter, qualifikation_Mitarbeiter);
			alle_Mitarbeiter.push_back(mitarbeiter);
		}
		if(input2 == 2) //Intervall hinzufuegen
		{
			cout<< "Nennen Sie die Länge des Intervalls:";
			cin>> laenge_Intervall;
			Intervall intervall = Intervall(laenge_Intervall);
			alle_Intervalle.push_back(intervall);
		}
		if(input2 == 3) //Firma hinzufuegen 
		{
			cout<< "Nennen Sie die ID der Firma:";
			cin>> id_Firma;

			cout<< "Nennen Sie den Namen der Firma:";
			cin>> name_Firma;

			Firma firma = Firma(id_Firma, name_Firma);
			alle_Firmen.push_back(firma);
		}
		if(input2 == 4) //Wartungsplan hinzufuegen
		{
			string name_Wartungsplan;
			string notwendige_Qualifikation;
			Maschine maschine;
			Intervall intervall;
			Mitarbeiter mitarbeiter;
			Firma firma;
			

			//neue ID waehlen:
			int newID = 0;
			if(!alle_Wartungsplaene.empty())
			{
				newID = alle_Wartungsplaene.back().getid_Wartungsplan()+1;
			}


			cout<< "Nennen Sie den Namen des Wartungsplans:";
			cin>> name_Wartungsplan;

			cout<< "Nennen Sie die notwendige Qualifikation:";
			cin>> notwendige_Qualifikation;

			if(alle_Intervalle.empty())
			{
				cout<<"Es gibt kein Intervall zur Auswahl. Bitte legen Sie zuerst ein Intervall an."<<endl;
			}
			else
			{
				cout<< "Waehlen Sie ein Intervall aus folgender Liste aus:";
				for(Intervall i: alle_Intervalle)
				{
					cout<<"Intervall: "<<i.getlaenge_Intervall()<<endl;
				}
				int tempLaenge;
				cin>>tempLaenge;

				for(Intervall i: alle_Intervalle)
				{
					if(i.getlaenge_Intervall() == tempLaenge)
					{
						intervall = i;
					}
				}
				if(intervall.getlaenge_Intervall() != tempLaenge)
				{
					//Das Intervall wurde nicht gefunden!
					return -1;
				}
				
				cout<<"Waehlen Sie die ID des gewuenschten Mitarbeiters:"<<endl;
				for (Mitarbeiter i: alle_Mitarbeiter)
				{
					cout << i.getid_Mitarbeiter() << '\t' <<i.getname_Mitarbeiter() <<endl;
				}
				int temp_mitarbeiter_id;
				cin >> temp_mitarbeiter_id;

				bool mitarbeiter_found = false;
				for (Mitarbeiter i: alle_Mitarbeiter)
				{
					if(i.getid_Mitarbeiter() == temp_mitarbeiter_id)
					{
						mitarbeiter = i;
						mitarbeiter_found = true;
					}
				}
				if(mitarbeiter_found==false)
				{
					//Mitarbeiter nicht gefunden
					return -1;
				}

				cout<<"Waehlen Sie die ID der gewuenschten Firma:"<<endl;
				for (Firma i: alle_Firmen)
				{
					cout << i.getid_Firma() << '\t' <<i.getname_Firma() <<endl;
				}
				int temp_firma_id;
				cin >> temp_firma_id;

				bool firma_found = false;
				for (Firma i: alle_Firmen)
				{
					if(i.getid_Firma() == temp_firma_id)
					{
						firma = i;
						firma_found = true;
					}
				}
				if(firma_found==false)
				{
					//firma nicht gefunden
					return -1;
				}
				Wartungsplan neuer_Wartungsplan = Wartungsplan(newID, name_Wartungsplan, notwendige_Qualifikation, maschine, intervall, mitarbeiter, firma);
				alle_Wartungsplaene.push_back(neuer_Wartungsplan);
			}
		}
	}
	else if (input == 1)
	{
		cout<< "Was möchten Sie löschen?" <<endl;
		cout<< "0: Maschine" <<endl;
		cout<< "1: Mitarbeiter" <<endl;
		cout<< "2: Firma" <<endl;
		cout<< "3: Wartungsplan" <<endl;
		cin>> input2;

		if(input2 == 0) // Maschine loeschen
		{
			cout<< "Nennen Sie die ID der zu löschenden Maschine:";
			for (Firma i: alle_Firmen)
			{
				for(Maschine j: i.get_alle_Maschinen())
				{
					cout << j.getid_Maschine() << '\t' << j.getname_Maschine() << endl;
				}
			}
			int temp_id_maschine;
			cin>> temp_id_maschine;
			bool maschine_found = false;
			for (Firma i: alle_Firmen)
			{
				for(Maschine j: i.get_alle_Maschinen())
				{
					if(j.getid_Maschine() == temp_id_maschine)
					{
						maschine_found = true;
						//alle passenden Wartungsplaene loeschen;
						for(int k = 0; k<alle_Wartungsplaene.size();k++)
						{
							if(alle_Wartungsplaene[k].getMaschine().getid_Maschine() == temp_id_maschine)
							{
								//wartungsplan entfernen
								alle_Wartungsplaene.erase(alle_Wartungsplaene.begin()+k);
							}
						}
						//jetzt Maschine aus Firma loeschen
						i.del_Maschine(j.getid_Maschine());
					}
				}
			}
			if(maschine_found == false)
			{
				//maschine nicht gefunden.
				cout<<"Eingabe ungueltig: Maschine nicht gefunden."<<endl;
				return -1;
			}
		}
		if(input2 == 1) // Mitarbeiter loeschen
		{
			cout<< "Nennen Sie die ID des zu löschenden Mitarbeiters:";
			for(Mitarbeiter i: alle_Mitarbeiter)
			{
				cout<<i.getid_Mitarbeiter()<<"\t"<<i.getname_Mitarbeiter();
			}
			
			int temp_id_mitarbeiter;
			cin>> temp_id_mitarbeiter;

			bool mitarbeiter_found = false;

			//Referenzen in Firmen loeschen
			for(Firma i: alle_Firmen)
			{
				for(Mitarbeiter j: i.get_alle_Mitarbeiter())
				{
					if(j.getid_Mitarbeiter() == temp_id_mitarbeiter)
					{
						//Mitarbeiter aus firma entfernen
						i.del_Mitarbeiter(temp_id_mitarbeiter);
					}
				}
			}

			//Mitarbeiter aus Liste der Mitarbeiter loeschen
			for (int i = 0; i<alle_Mitarbeiter.size(); i++)
			{
				if(alle_Mitarbeiter[i].getid_Mitarbeiter() == temp_id_mitarbeiter)
				{
					alle_Mitarbeiter.erase(alle_Mitarbeiter.begin()+i);
				}
			}
		}
		if(input2 == 2) // Firma loeschen
		{
			cout<< "Nennen Sie die ID der zu löschenden Firma:";
			for (Firma i: alle_Firmen)
			{
				cout << i.getid_Firma() << '\t' << i.getname_Firma() << endl;
			}
			int temp_id_firma;
			cin>>temp_id_firma;
		
			//Erst alle Maschinen loeschen.

			//Firma finden
			for(Firma i: alle_Firmen)
			{
				if(i.getid_Firma() == temp_id_firma)
				{
					//firma gefunden, durch alle Maschinen iterieren
					for(Maschine j: i.get_alle_Maschinen())
					{
						//alle passenden Wartungsplaene loeschen;
						for(int k = 0; k<alle_Wartungsplaene.size();k++)
						{
							if(alle_Wartungsplaene[k].getMaschine().getid_Maschine() == j.getid_Maschine())
							{
								//wartungsplan entfernen
								alle_Wartungsplaene.erase(alle_Wartungsplaene.begin()+k);
							}
						}
						//jetzt Maschine aus Firma loeschen
						i.del_Maschine(j.getid_Maschine());
					}
				}
				
			}

			//Firma aus Liste der Firmen loeschen
			for (int i = 0; i<alle_Firmen.size(); i++)
			{
				if(alle_Firmen[i].getid_Firma() == temp_id_firma)
				{
					alle_Firmen.erase(alle_Firmen.begin()+i);
				}
			}
			

		}
		if(input2 == 3) // Wartungsplan loeschen
		{
			cout<< "Nennen Sie die ID des zu löschenden Wartungsplans:";
			for(Wartungsplan i: alle_Wartungsplaene)
			{
				cout<<i.getid_Wartungsplan()<<"\t"<<i.getname_Wartungsplan();
			}
			
			int temp_id_wartungsplan;
			cin>> temp_id_wartungsplan;

			bool wartungsplan_found = false;

			//wartungsplan aus Liste der wartungsplaene loeschen
			for (int i = 0; i<alle_Wartungsplaene.size(); i++)
			{
				if(alle_Wartungsplaene[i].getid_Wartungsplan() == temp_id_wartungsplan)
				{
					wartungsplan_found = true;
					alle_Wartungsplaene.erase(alle_Wartungsplaene.begin()+i);
				}
			}
			if(!wartungsplan_found)
			{
				//wartungsplan nicht gefunden
				cout<<"Wartungsplan nicht gefunden.";
				return -1;
			}
		}
		
	}
	else if (input == 2)
	{
		cout<< "Was möchten Sie exportieren?" <<endl;
		cout<< "0: Alle Maschinen" <<endl;
		cout<< "1: Alle Mitarbeiter" <<endl;
		cout<< "2: Alle Wartungsintervalle" <<endl;
		cout<< "3: Alle Wartungspläne" <<endl;
		cin>> input2;

		/*if(input2 == 0)
		//Exportieren der Daten in .txt!!
		//define array of strings
		string alle_Maschinen[10] = { "value0", "value1", "value2","value3", "value4", "value5","value6", "value7","value8", "value9" }; //können wir alle_Mitarbeiter direkt nehmen, ist schon ein Vektor!!
		//open file for writing
		ofstream fw("C:\\Users\\Besitzer\\Documents\\GitHub\\CAE_Bonusaufgabe\\alle_Maschinen.txt", std::ofstream::out);
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
		//close the file after the writing operation is completed
		fw.close();*/
	}
	else if(input == 3)
	{
		//Importieren der Daten aus .txt!!
	}
	else if (input == 4)
	{
		//Ausgeben der Übersicht!!
	}
	else if(input == 5)
	{
		// cancel the program
		run = false;
	}
	else
	{
		// ungültige Eingabe.
		run = false;
	}
	return 0;
}

int main()
{
	run = true;
	//run the loop while program is running, unless it is cancelled.
	while(run==true)
	{
		if(loop()<0)
		{
			run = false;
			return -1;
		}
	}

}