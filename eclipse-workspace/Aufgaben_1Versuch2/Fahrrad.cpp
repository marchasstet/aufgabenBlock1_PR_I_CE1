/*
 * Fahrrad.cpp
 *
 *  Created on: 24.11.2023
 *      Author: marcd
 */

#include "Fahrrad.h"

#include "GlobaleUhr.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
Fahrrad::Fahrrad() {
	Fahrzeug::p_dGeschwindigkeit=0;
	// TODO Auto-generated constructor stub

}
Fahrrad::Fahrrad(std::string sName, double dMaxGeschwindigkeit)
    : Fahrzeug(sName, dMaxGeschwindigkeit) {
	p_dGeschwindigkeit=dMaxGeschwindigkeit;
    // Additional initialization for Fahrrad
}
Fahrrad::~Fahrrad() {
	// TODO Auto-generated destructor stub
}



void  Fahrrad::vAusgeben(ostream& out) const {// spezifischer vAusgeben für Fahrrad  4.3.1

    Fahrzeug::vAusgeben(out);

 cout<<  "\n";

}
void Fahrrad::vSimulieren() { //spezifischer vSimulieren für Fahrrad  4.3.1

	Fahrzeug::vSimulieren();
	dGeschwindigkeit();
}

double Fahrrad::dGeschwindigkeit(){
	 double p_ddGeschwindigkeit = p_dMaxGeschwindigkeit * pow(0.9, (int)(p_dGesamtStrecke / 20.0));
	 Fahrzeug::p_dGeschwindigkeit= max(p_ddGeschwindigkeit, 12.0);
	 return Fahrzeug::p_dGeschwindigkeit;
//	int counter=1;
//	if(p_dGesamtStrecke/20 == counter){p_dGeschwindigkeit=p_dGeschwindigkeit*0.9;// denkfehler in der logik
//
//				if(p_dGeschwindigkeit<=12){
//					p_dGeschwindigkeit=12;
//				}
//
//	}
//
//	else{
//		  // max funktion auch möglich
//		}
//	counter++;
//		return 0;
}

	// schlechte implementierung neu überlegen falls zeit gerade nicht linear implemeintiert sondern wie summe unter funktion möglich auch linear aber aufgaben stellung komisch



