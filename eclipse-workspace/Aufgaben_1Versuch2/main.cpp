/*
 * main.cpp
 *
 *  Created on: 20.11.2023
 *      Author: marcd
 */
// Für Zahl punkt ist für aufgaben teil bsp 3. Aufgaben teil 3
#include <iostream>
#include "Fahrzeug.h"
#include "GlobaleUhr.h"
#include <string>
#include <memory>
#include <vector>
#include "Pkw.h"
#include "Fahrrad.h"
#include <algorithm>
#include <math.h>
using namespace std;
//veersuch um u gucken ob damit man gucken kann dass die for scheife nur funktoniert mit dem type int habt nicht geklappt
template<typename ExpectedType, typename GivenType>
bool isTypeMatch(const GivenType &variable) {
	return typeid(variable) == typeid(ExpectedType);
}

extern double p_dGlobalezeit;
//definition der funktionen
void vAufgabe_1();
void vAufgabe1_a();
void vAufgabe_2();
void vAufgabe3();
void vAufgabe_Probe();
void vAufgabe_AB1();
void vAufgabeProbe();
// vergleichs operator deklarieern und definieren für die überladung
ostream& operator<<(ostream &o, const Fahrzeug &f) {
	f.vAusgeben(o);
	return o;
}// in die oberklassse Simulations objekt

int main() {


	    int choice;

	    do {
	        // Display menu
	        std::cout << "Menu:" << std::endl;
	        std::cout << "1. Aufgabe 1" << std::endl;
	        std::cout << "2. Aufgabe 1a" << std::endl;
	        std::cout << "3. Aufgabe 2" << std::endl;
	        std::cout << "4. Aufgabe 3" << std::endl;
	        std::cout << "5. vAufgabe_Probe 3" << std::endl;
	        std::cout << "6. vAufgabe_AB1 3" << std::endl;
	        std::cout << "7. test" << std::endl;
	        std::cout << "0. Quit" << std::endl;

	        // Get user choice
	        std::cout << "Enter your choice: ";
	        std::cin >> choice;

	        // Execute the corresponding function based on user choice
	        switch (choice) {
	        case 1:
	        	vAufgabe_1();
	            break;
	        case 2:
	        	vAufgabe1_a();
	            break;
	        case 3:
	            vAufgabe_2();
	            break;
	        case 4:
	        	vAufgabe3();
	            break;
	        case 5:
	        	 vAufgabe_Probe();
	        	            break;
	        case 6:
	        	vAufgabe_AB1();
	        	            break;
	        case 7:
	        	vAufgabeProbe();
	        	break;
	        case 0:
	            std::cout << "Terminating the program." << std::endl;
	            break;
	        default:
	            std::cout << "Invalid choice. Please try again." << std::endl;
	        }

	    } while (choice != 0);

	    // Aus dem online Vortest
	    //vAufgabe_AB1();

	    return 0;

	}

	//vAufgabe3();

//	GlobaleUhr Uhr1;
//    Fahrzeug Fahrzeug2("Fahrzeug",100);//obj erstellung
//    Fahrzeug Fahrzeug3("Fahrzeug",300);//obj erstellung
//    std::cout << "hello" << std::endl;
//    Fahrzeug1.vKopf();
	// Fahrzeug1.vKopf();

	//cout<< Fahrzeug1;
//    //Uhr1.dGlobaleZeit++;
//    Fahrzeug1.vAusgeben();
//    Fahrzeug2.vAusgeben();
//    Fahrzeug3.vAusgeben();
//    Uhr1.aktualisiereZeit();
//    Fahrzeug1.vKopf();
//    Fahrzeug1.vSimulieren();
//    Fahrzeug1.vAusgeben();
//    Fahrzeug2.vSimulieren();
//    Fahrzeug2.vAusgeben();
//    Fahrzeug3.vSimulieren();
//    Fahrzeug3.vAusgeben();
//    Uhr1.aktualisiereZeit();
//    Fahrzeug2.vSimulieren();
//    Fahrzeug2.vAusgeben();

//vAufgabe1_a();

	//vAufgabe_2();

//definition funk
void vAufgabe_1()
{
	//Statische obj für 4.
	Fahrzeug stAuto("fStatisch1");
	Fahrzeug stAuto2("fStatisch2");

	//dynamisch Für 4.
	Fahrzeug* dAuto1= new Fahrzeug("fdynamisch1");
	Fahrzeug* dAuto2= new Fahrzeug("fdynamisch2");

	delete dAuto1;
	delete dAuto2;
//unique ptr Für 4.
	make_unique<Fahrzeug>;
  auto uAuto1 = make_unique<Fahrzeug>("uAuto1");
  auto uAuto2 = make_unique<Fahrzeug>("uAuto2");
//shared ptr Für 4.
  auto sAuto = make_shared<Fahrzeug>("sAuto1");
  auto sAuto2 = make_shared<Fahrzeug>("sAuto2");
 // eienem neuen Shared ptr einen anderem Shared ptr zuordnen 4.
  auto sAuto3 = sAuto2;
 // use count fürt den Shared ptr
  cout << "use count:" << sAuto2.use_count()<< endl;
  //Versuchen unique ptr einen anderem unique ptr zuzuordnen ergibt error 4.
  //auto uAuto4 = uAuto2;
  // vector für unique ptr erzeugen
  vector<unique_ptr<Fahrzeug>> uniqueAutoVector ;
  //wenn nur uniqueAutoVector.push_back(uAuto1); gemacht wird funktionierts nicht da unique pointer
  //zur frage ausm Skript Die Vektroren müssen über move übertragen werden 4.
  uniqueAutoVector.push_back(std::move(uAuto1));
  uniqueAutoVector.push_back(std::move(uAuto2));
  // löshen des Vector unique ptr werden alle zerstört
  uniqueAutoVector.clear();
  // Hier sollte Theoretisch der destruktor für die einzelden unique ptr azfgerufen werden
  // shared pointer müssten egal sein wegen der selbstverwaltung 4.
  //wie oben nur statt vector als unique ptr nun als shared ptr
  vector<shared_ptr<Fahrzeug>> sharedAutoVector;
  sharedAutoVector.push_back(std::move(sAuto));//mit move 4. warum ist doch eig bei shared ptr unnötig
  sharedAutoVector.push_back(sAuto2);// ohne  move 4.
  cout << "shared ptr use count nach dem move command" <<endl;

}
void vAufgabe1_a(){
 vector<unique_ptr<Fahrzeug>> Fahrzeuge;
 int anzahlFahrzeuge;
 double dZeittakt;
 double dSimulationszeit;
  cout << "wie viel Fahrzeuge sollten erstellt werden?"<< endl;
  cout << "Anzahl der zu erstellenden Fahrzeuge:"<< endl;
  cin >> anzahlFahrzeuge;
  cout<< "Mit welchem Zeittakt soll die Simulation laufen?"<< endl;
  cin>>dZeittakt ;
  cout<< "Wie lange soll die Simulation laufen?"<< endl;
  cin>> dSimulationszeit;
  cout << "Anzahl der zu erstellenden Fahrzeuge:"<< anzahlFahrzeuge<< endl;
  cout<< "Zeitakt:"<< dZeittakt <<endl;
  cout << "Simuationszeit:" << dSimulationszeit << endl;
	for (int i = 0; i < anzahlFahrzeuge; i++) {
	        string sFahrzeugName="";
	        double dMaxGeschwindigkeit=0;

	   cout << "Gebe den Namen des Fahrzeugs " << i + 1 << " ein: "<< endl;
       std::cin >> sFahrzeugName;
       cout << "" <<endl;

	   cout << "Gebe die Maximalgeschwindigkeit des Fahrzeugs " << i + 1 << " ein: "<<endl;
	   std::cin >> dMaxGeschwindigkeit;
	   cout << "" <<endl;
	        // Erzeugen Sie ein einzigartiges Fahrzeug und fügen Sie es zum Vektor hinzu
	        Fahrzeuge.push_back(make_unique<Fahrzeug>(sFahrzeugName, dMaxGeschwindigkeit));
	    }


	Fahrzeug Fahrzeug1("",1);
	Fahrzeug1.vKopf();
	int xnt=1;
	    for (p_dGlobalezeit = 0.0; p_dGlobalezeit <= dSimulationszeit; p_dGlobalezeit += dZeittakt) {
	    	   cout<< xnt<<"te Simulation ---------------------------------------"<< endl;
	    	   xnt++;
	        for (const auto& pFahrzeug : Fahrzeuge) {


				pFahrzeug->vSimulieren();
	           cout<< *pFahrzeug<<endl;

	        }
	    }
}
void vAufgabe_2() { // Die Sachen funktionenn weil Fahrzueug eine Anbstrakte klasse ist,dh keine direkten instanzen von Fahrzeug man kann aber pointer auf Fahrzezg verwenden um objekte von unterklassen aka Fahrrad und PKW zu speichern
	vector<unique_ptr<Fahrzeug>> Fahrzeuge; //vektor initialisierung vektor ist leer
	int anzahlPKWs = 0, anzahlFahrrad = 0; // deklar var zähler
	double dZeittakt = 0;
	double dSimulationszeit = 0;
	// anfragen der einzelnen daten für die simulation
	cout << "Anzahl der zu erstellenden PKWs: " << endl;
	cin >> anzahlPKWs;
	cout << "Anzahl der zu erstellenden Fahrräder: " << endl;
	cin >> anzahlFahrrad;
	cout << "Mit welchem Zeittakt soll die Simulation laufen?" << endl;
	cin >> dZeittakt;
	cout << "Wie lange soll die Simulation laufen?" << endl;
	cin >> dSimulationszeit;
	cout << "Anzahl der zu erstellenden PKWs: " << anzahlPKWs << endl;
	cout << "Anzahl der zu erstellenden Fahrräder: " << anzahlFahrrad << endl;
	cout << "Zeitakt:" << dZeittakt << endl;
	cout << "Simuationszeit:" << dSimulationszeit << endl;

	if (isTypeMatch<int>(anzahlPKWs)) {

		//erstellung obj für pkw und speicherung im vctr
		for (int i = 0; i < anzahlPKWs; i++) {
			string name;
			double maxGeschwindigkeit, verbrauch, tankvolumen;

			cout << "PKW " << i + 1 << " - Name: ";
			cin >> name;

			cout << "PKW " << i + 1 << " - Maximalgeschwindigkeit: ";
			cin >> maxGeschwindigkeit;

			cout << "PKW " << i + 1 << " - Verbrauch (Liter/100km): ";
			cin >> verbrauch;

			cout << "PKW " << i + 1 << " - Tankvolumen: ";
			cin >> tankvolumen;

			Fahrzeuge.push_back(
					make_unique<Pkw>(name, maxGeschwindigkeit, verbrauch,
							tankvolumen));
		}

		/*Danke an Chat GPT an der Stelle:Abstrakte Klasse Fahrzeug: Die Klasse Fahrzeug ist abstrakt, was bedeutet, dass Sie keine direkten Instanzen von Fahrzeug erstellen können. Sie können jedoch Zeiger auf Fahrzeug verwenden, um Objekte ihrer abgeleiteten Klassen (z. B. PKW und Fahrrad) zu speichern.
		 Polymorphie: Durch die Verwendung von Zeigern auf die abstrakte Klasse Fahrzeug können Sie Polymorphie nutzen. Das bedeutet, dass Sie sowohl PKWs als auch Fahrräder in einem Vektor speichern können und trotzdem auf die spezifischen Funktionen der abgeleiteten Klassen zugreifen können, wenn Sie auf die Zeiger zugreifen.
		 Gemeinsame Schnittstelle: Da sowohl PKWs als auch Fahrräder von der Klasse Fahrzeug abgeleitet sind, haben sie eine gemeinsame Schnittstelle. Das bedeutet, dass Sie sie in einem gemeinsamen Container (wie einem Vektor) speichern können und auf ihre gemeinsamen Funktionen zugreifen können, unabhängig von der spezifischen Implementierung.Durch die Verwendung von Smart Pointern (hier unique_ptr) wird das Management des Speichers vereinfacht, da die Objekte automatisch freigegeben werden, wenn der Vektor oder der Smart Pointer außerhalb ihres Gültigkeitsbereichs geht. */

					//erstellung obj für Fahrrad
			for (int i = 0; i < anzahlFahrrad; i++) {
				string name;
				double maxGeschwindigkeit;

				cout << "Fahrrad " << i + 1 << " - Name: ";
				cin >> name;

				cout << "Fahrrad " << i + 1 << " - Maximalgeschwindigkeit: ";
				cin >> maxGeschwindigkeit;

				Fahrzeuge.push_back(
						make_unique<Fahrrad>(name, maxGeschwindigkeit));
			}
		}
		Pkw rand("", 0.0, 0, 0);

		for (p_dGlobalezeit = 0.0;
				p_dGlobalezeit <= dSimulationszeit;
				p_dGlobalezeit += dZeittakt) {
			cout << "\nSimulation bei Zeit " << p_dGlobalezeit
					<< " Stunden\n" << endl; // einheiten sind durcheinander fixen !!!!
			if (static_cast<int>(p_dGlobalezeit) >= 3) {
				if (static_cast<int>(p_dGlobalezeit) % 3 == 0) {
					cout << "\nNach 3 Stunden: Alle PKWs werden vollgetankt."
							<< endl;
					for (const auto &fahrzeug : Fahrzeuge) {
						// Überprüfen, ob es sich um ein PKW handelt, um dTanken aufzurufen
						Pkw *pkw = dynamic_cast<Pkw*>(fahrzeug.get());
						if (pkw != nullptr) {
							double getankteMenge = pkw->dTanken(); // Standardmäßig wird vollgetankt
							cout << "PKW " << fahrzeug->getName()
									<< " wurde um " << getankteMenge
									<< " Liter getankt." << endl;
						}
					}
				}
			}
				rand.vKopf();
				for (const auto &fahrzeug : Fahrzeuge) {


					cout << *fahrzeug << endl;

					fahrzeug->vSimulieren();
				}

			}


			}



void vAufgabe3() {
	Pkw auto1("fk", 100.0, 3, 2);
	Pkw auto2("ff", 200.0, 2, 4);
	p_dGlobalezeit = 1;
	auto2.vSimulieren();
	auto2.vKopf();
	cout << auto1;
	cout << auto2;
	auto2 < auto1;
	auto1 = auto2;
	cout << auto1;
}

double dEpsilon = 0.001;

void vAufgabe_Probe() {
    Fahrzeug* pF1 = new Pkw("Audi", 150, 8,0);
    p_dGlobalezeit = 0.0;
    Fahrzeug::vKopf();
    pF1->vSimulieren();
    p_dGlobalezeit = 5.0;
    cout << endl << "Globalezeit = " << p_dGlobalezeit << endl;
    pF1->vSimulieren();

    cout << *pF1 << endl;
    delete pF1;
    char c;
    cin >> c;
}
void vAufgabe_AB1() {

    int l = 0; // Laufindex für gezielte AUsgabe
    vector<int> ausgabe{13};
    double dTakt = 0.4;

    std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
    vecFahrzeuge.push_back(make_unique <Pkw>("Audi", 217, 10.7));
    vecFahrzeuge.push_back(make_unique <Fahrrad>("BMX", 24.7));
    for (p_dGlobalezeit = 0; p_dGlobalezeit < 10; p_dGlobalezeit += dTakt)
    {
        auto itL = find(ausgabe.begin(), ausgabe.end(), l);
        if (itL != ausgabe.end()) {
            std::cout << std::endl << l <<  " Globalezeit = " << p_dGlobalezeit << std::endl;
            Fahrzeug::vKopf();
        }

        for (int i = 0; i < (int) vecFahrzeuge.size(); i++)
        {
            vecFahrzeuge[i]->vSimulieren();
            if (fabs(p_dGlobalezeit - 3.0) < dTakt/2)
            {
                vecFahrzeuge[i]->dTanken();
            }
            if (itL != ausgabe.end()) {
                std::cout << *vecFahrzeuge[i] << endl;
            }
        }
        l++;
    }
    char c;
    std::cin >> c;
}
void vAufgabeProbe(){
	Fahrzeug* pF1= new Pkw("Audi",150,8,55);
	p_dGlobalezeit=0.0;
	Fahrzeug::vKopf();
	std::cout<<*pF1<<endl;
	Fahrzeug::vKopf();

	p_dGlobalezeit=5.0;
	std::cout<<endl<< "Globalezeit = " << p_dGlobalezeit << endl;
	pF1->vSimulieren();
    std::cout<<*pF1<<endl;
	delete pF1;
	char c;
	std::cin >> c;
}
