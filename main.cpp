#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <sstream>

#include "mitarbeiter.h"
#include "intervall.h"
#include "wartungsplan.h"
#include "maschfirma.h"

using namespace std;

int loop(vector<Mitarbeiter>& alle_Mitarbeiter, 
	vector<Maschine>& alle_Maschinen,
	vector<Intervall>& alle_Intervalle,
	vector<Wartungsplan>& alle_Wartungsplaene,
	vector<Firma>& alle_Firmen, bool& run)
{


	//Hauptmenue:

	cout<< "Willkommen im Hauptmenue, bitte waehlen Sie eine Aktion aus." <<endl;
	cout<< "0: Element hinzufuegen" <<endl;
	cout<< "1: Element loeschen" <<endl;
	cout<< "2: Export Textdatei" <<endl;
	cout<< "3: Import Textdatei" <<endl;
	cout<< "4: Uebersicht anzeigen" <<endl;

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
		cout<< "Was moechten Sie hinzufuegen?" <<endl;
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
			cout<< "Nennen Sie die ID der gewuenschten Firma:";
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
			alle_Maschinen.push_back(tempMaschine);
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
			cout<< "Nennen Sie die Laenge des Intervalls:";
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
		cout<< "Was moechten Sie loeschen?" <<endl;
		cout<< "0: Maschine" <<endl;
		cout<< "1: Mitarbeiter" <<endl;
		cout<< "2: Firma" <<endl;
		cout<< "3: Wartungsplan" <<endl;
		cin>> input2;

		if(input2 == 0) // Maschine loeschen
		{
			cout<< "Nennen Sie die ID der zu loeschenden Maschine:";
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
			cout<< "Nennen Sie die ID des zu loeschenden Mitarbeiters:";
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
			cout<< "Nennen Sie die ID der zu loeschenden Firma:";
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
			cout<< "Nennen Sie die ID des zu loeschenden Wartungsplans:";
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
		cout<< "Was moechten Sie exportieren?" <<endl;
		cout<< "0: Alle Maschinen" <<endl;
		cout<< "1: Alle Mitarbeiter" <<endl;
		cout<< "2: Alle Wartungsintervalle" <<endl;
		cout<< "3: Alle Wartungsplaene" <<endl;
		cin>> input2;

		if(input2 == 0)
		{
			ofstream Ausgabe;
			Ausgabe.open("Alle_Maschinen.txt");

			if (Ausgabe)
				
				for (Maschine i: alle_Maschinen)
				{
					Ausgabe << i.getid_Maschine() << '\t' <<i.getname_Maschine() << '\t' <<i.getfirma().getname_Firma() <<endl;
				}
				
			Ausgabe.close();
		}

		if(input2 == 1)
		{
			ofstream Ausgabe;
			Ausgabe.open("Alle_Mitarbeiter.txt");

			if (Ausgabe)
				
				for (Mitarbeiter i: alle_Mitarbeiter)
				{
					Ausgabe << i.getid_Mitarbeiter() << '\t' <<i.getname_Mitarbeiter() << '\t' <<i.getqualifikation_Mitarbeiter() <<endl;
				}
				
			Ausgabe.close();
		}

		if(input2 == 2)
		{
			ofstream Ausgabe;
			Ausgabe.open("Alle_Intervalle.txt");

			if (Ausgabe)
				
				for (Intervall i: alle_Intervalle)
				{
					Ausgabe << i.getlaenge_Intervall() <<endl;
				}
				
			Ausgabe.close();
		}

		if(input2 == 3)
		{
			ofstream Ausgabe;
			Ausgabe.open("Alle_Wartungsplaene.txt");

			if (Ausgabe)
				
				for (Wartungsplan i: alle_Wartungsplaene)
				{
					Ausgabe << i.getid_Wartungsplan() << '\t' <<i.getname_Wartungsplan() << '\t' <<i.getnotwendige_Qualifikation() << '\t' <<i.getMaschine().getname_Maschine() << '\t' <<i.getIntervall().getlaenge_Intervall() << '\t' <<i.getMitarbeiter().getname_Mitarbeiter() << '\t' <<i.getFirma().getname_Firma() <<endl;
				}
				
			Ausgabe.close();
		}
	}
	else if(input == 3)
	{
		//Importieren der Daten aus .txt!!
		cout<< "Was moechten Sie importieren?" <<endl;
		cout<< "0: Alle Maschinen" <<endl;
		cout<< "1: Alle Mitarbeiter" <<endl;
		cout<< "2: Alle Wartungsintervalle" <<endl;
		cout<< "3: Alle Wartungsplaene" <<endl;
		cin>> input2;

		if(input2 == 0) //importieren der Maschinen
		{
			ifstream Eingabe;
			Eingabe.open("Alle_Maschinen.txt");
			string zeile;
			
			

			if (Eingabe)
			{
				//Bestimmung der Anzahl der Zeilen
				int anzahl = 0;
				while(getline(Eingabe, zeile)) anzahl++; 
				Eingabe.close();
				
				//Öffnen und Einlesen der Attribute des Objektes
				ifstream Eingabe;
				Eingabe.open("Alle_Maschinen.txt");
				for (int n = 1; n <= anzahl; n++)
				{
					getline(Eingabe, zeile);
					Maschine current_Maschine;
					char del = '\t';
					stringstream ss(zeile);
					string word;
					int k= 0;

					while (!ss.eof()) 
					{
						k = k + 1;
						getline(ss, word, del);
						cout << word << endl;
						if (k==1)
						{
							int current_id_Maschine = stoi(word); //String zu Int kovertieren
							current_Maschine.setid_Maschine(current_id_Maschine);
						}
						if (k==2)
						{
							string current_name_Maschine = word;
							current_Maschine.setname_Maschine(current_name_Maschine);
						}
						if (k==3)
						{
							string current_name_Firma = word;
							Firma current_Firma;
							for (Firma i : alle_Firmen)
							{
								if (i.getname_Firma() == current_name_Firma)
								{
									current_Firma = i;
								}
							}
							current_Maschine.setfirma(current_Firma);
							current_Firma.add_Maschine(current_Maschine);
						}
					}
					alle_Maschinen.push_back(current_Maschine); //Objekt zum Vektor hinzufügen
				}
				
				
				
			}
		}

		if(input2 == 1) //importieren der Mitarbeiter
		{
		ifstream Eingabe;
		Eingabe.open("Alle_Mitarbeiter.txt");
		string zeile;
			
			

			if (Eingabe)
			{
				//Bestimmung der Anzahl der Zeilen
				int anzahl = 0;
				while(getline(Eingabe, zeile)) anzahl++; 
				Eingabe.close();
				
				//Öffnen und Einlesen der Attribute des Objektes
				ifstream Eingabe;
				Eingabe.open("Alle_Mitarbeiter.txt");
				for (int n = 1; n <= anzahl; n++)
				{
					getline(Eingabe, zeile);
					Mitarbeiter current_Mitarbeiter;
					char del = '\t';
					stringstream ss(zeile);
					string word;
					int k= 0;

					while (!ss.eof()) 
					{
						k = k + 1;
						getline(ss, word, del);
						cout << word << endl;
						if (k==1)
						{
							int current_id_Mitarbeiter = stoi(word); //String zu Int kovertieren
							current_Mitarbeiter.setid_Mitarbeiter(current_id_Mitarbeiter);
						}
						if (k==2)
						{
							string current_name_Mitarbeiter = word;
							current_Mitarbeiter.setname_Mitarbeiter(current_name_Mitarbeiter);
						}
						if (k==3)
						{
							string current_qualifikation_Mitarbeiter = word;
							current_Mitarbeiter.setqualifikation_Mitarbeiter(current_qualifikation_Mitarbeiter);
						}
					}
					alle_Mitarbeiter.push_back(current_Mitarbeiter); //Objekt zum Vektor hinzufügen
				}
				
				
				
			}
		}

		if(input2 == 2) //importieren der Intervalle
		{
		ifstream Eingabe;
		Eingabe.open("Alle_Wartungsintervalle.txt");
		string zeile;
			
			

			if (Eingabe)
			{
				//Bestimmung der Anzahl der Zeilen
				int anzahl = 0;
				while(getline(Eingabe, zeile)) anzahl++; 
				Eingabe.close();
				
				//Öffnen und Einlesen der Attribute des Objektes
				ifstream Eingabe;
				Eingabe.open("Alle_Wartungsintervalle.txt");
				for (int n = 1; n <= anzahl; n++)
				{
					getline(Eingabe, zeile);
					Intervall current_Wartungsintervall;
					int current_laenge_Intervall = stoi(zeile); //String zu Int kovertieren
					current_Wartungsintervall.setlaenge_Intervall(current_laenge_Intervall);
					alle_Intervalle.push_back(current_Wartungsintervall); //Objekt zum Vektor hinzufügen
				}
				
				
				
			}
		}

		if(input2 == 3) //importieren der Wartungspläne
		{
			ifstream Eingabe;
			Eingabe.open("Alle_Wartungsplaene.txt");
			string zeile;
			
			

			if (Eingabe)
			{
				//Bestimmung der Anzahl der Zeilen
				int anzahl = 0;
				while(getline(Eingabe, zeile)) anzahl++; 
				Eingabe.close();
				
				//Öffnen und Einlesen der Attribute des Objektes
				ifstream Eingabe;
				Eingabe.open("Alle_Wartungsplaene.txt");
				for (int n = 1; n <= anzahl; n++)
				{
					getline(Eingabe, zeile);
					Wartungsplan current_Wartungsplan;
					char del = '\t';
					stringstream ss(zeile);
					string word;
					int k= 0;

					while (!ss.eof()) 
					{
						k = k + 1;
						getline(ss, word, del);
						cout << word << endl;
						if (k==1)
						{
							int current_id_Wartungsplan = stoi(word); //String zu Int kovertieren
							current_Wartungsplan.setid_Wartungsplan(current_id_Wartungsplan);
						}
						if (k==2)
						{
							string current_name_Wartungsplan = word;
							current_Wartungsplan.setname_Wartungsplan(current_name_Wartungsplan);
						}
						if (k==3)
						{
							string current_notwendige_Qualifikation = word;
							current_Wartungsplan.setnotwendige_Qualifikation(current_notwendige_Qualifikation);
						}
						if (k==4)
						{
							string current_name_Maschine = word;
							Maschine current_Maschine;
							for (Maschine i : alle_Maschinen)
							{
								if (i.getname_Maschine() == current_name_Maschine)
								{
									current_Maschine = i;
								}
							}
							current_Wartungsplan.setMaschine(current_Maschine);
						}
						if (k==5)
						{
							int currentIntervall = stoi(word); //String zu Int kovertieren
							current_Wartungsplan.setIntervall(currentIntervall);
						}
						if (k==6)
						{
							
							string current_name_Mitarbeiter = word;
							Mitarbeiter current_Mitarbeiter;
							
							for (Mitarbeiter i : alle_Mitarbeiter)
							{
								if (i.getname_Mitarbeiter() == current_name_Mitarbeiter)
								{
									current_Mitarbeiter = i;
								}
							}
							current_Wartungsplan.setmitarbeiter(current_Mitarbeiter);
						}
						if (k==7)
						{
							string current_name_Firma = word;
							Firma current_Firma;
							for (Firma i : alle_Firmen)
							{
								if (i.getname_Firma() == current_name_Firma)
								{
									current_Firma = i;
								}
							}
							current_Wartungsplan.setFirma(current_Firma);
						}
					}
					alle_Wartungsplaene.push_back(current_Wartungsplan); //Objekt zum Vektor hinzufügen
				}
				
				
				
			}
		}

	}
	else if (input == 4)
	{
		//Ausgeben der Übersicht!!
		cout<< "Was moechten Sie ausgeben?" <<endl;
		cout<< "0: Alle Maschinen" <<endl;
		cout<< "1: Alle Mitarbeiter" <<endl;
		cout<< "2: Alle Wartungsintervalle" <<endl;
		cout<< "3: Alle Wartungsplaene" <<endl;
		cin>> input2;

		if(input2 == 0)
		{
		
			for (Maschine i: alle_Maschinen)
			{
				cout << i.getid_Maschine() << '\t' <<i.getname_Maschine() << '\t' <<i.getfirma().getname_Firma() <<endl;
			}
				
			
		}

		if(input2 == 1)
		{

			for (Mitarbeiter i: alle_Mitarbeiter)
			{
				cout << i.getid_Mitarbeiter() << '\t' <<i.getname_Mitarbeiter() << '\t' <<i.getqualifikation_Mitarbeiter() <<endl;
			}
			
		}

		if(input2 == 2)
		{
	
			for (Intervall i: alle_Intervalle)
			{
				cout << i.getlaenge_Intervall() <<endl;
			}

		}

		if(input2 == 3)
		{

			for (Wartungsplan i: alle_Wartungsplaene)
			{
				cout << i.getid_Wartungsplan() << '\t' <<i.getname_Wartungsplan() << '\t' <<i.getnotwendige_Qualifikation() << '\t' <<i.getMaschine().getname_Maschine() << '\t' <<i.getIntervall().getlaenge_Intervall() << '\t' <<i.getMitarbeiter().getname_Mitarbeiter() << '\t' <<i.getFirma().getname_Firma() <<endl;
			}
			
		
		}
	}
	else if(input == 5)
	{
		// cancel the program
		run = false;
	}
	else
	{
		// ungültige Eingabe.
		cout << "Sie haben eine ungueltige Eingabe getroffen!" << endl;

		run = false;
	}
	return 0;
}

int main()
{
	vector<Mitarbeiter> alle_Mitarbeiter;
	vector<Maschine> alle_Maschinen;
	vector<Intervall> alle_Intervalle;
	vector<Wartungsplan> alle_Wartungsplaene;
	vector<Firma> alle_Firmen;
	bool run;
	run = true;
	//run the loop while program is running, unless it is cancelled.
	while(run==true)
	{
		if(loop(alle_Mitarbeiter, alle_Maschinen, alle_Intervalle,alle_Wartungsplaene, alle_Firmen, run)<0)
		{
			run = false;
			return -1;
		}
	}

}