/*
 * Fahrzeug.cpp
 *
 *  Created on: 02.11.2023
 *      Author: marcd
 */

#include "Fahrzeug.h"
#include "GlobaleUhr.h"
#include <iostream>
#include <string>
#include <iomanip>
#include<limits>
#include <memory>
#include <vector>
using namespace std;
extern double p_dGlobalezeit;

Fahrzeug::Fahrzeug() : p_iID(p_iMaxID++), p_sName(""), p_dMaxGeschwindigkeit(0) {
    cout << "Name des Objektes: " << p_sName << " \nID des Objektes: " << p_iID << endl;
}
// Konstruktor 3.
Fahrzeug::Fahrzeug(std::string sName) : p_iID(p_iMaxID++), p_sName(sName), p_dMaxGeschwindigkeit(0) {
   cout << "Name des Objektes: " << p_sName << " \nID des Objektes: " << p_iID << endl;
};
//Konstruktor 5.
Fahrzeug::Fahrzeug(std::string sName, double dMaxGeschwindigkeit)
    : p_iID(p_iMaxID++), p_sName(sName), p_dMaxGeschwindigkeit(dMaxGeschwindigkeit > 0 ? dMaxGeschwindigkeit : 0) {
    cout << "Name des Objektes: " << p_sName << " \nID des Objektes: " << p_iID
              << "\nMax Geschwindigkeit: " << p_dMaxGeschwindigkeit << endl;
}


 Fahrzeug::~Fahrzeug(){

 cout << "Name des gelöschten objektes: " << p_sName << " \nID des objektes: " << p_iID << endl;
}
	// TODO Auto-generated destructor stub


void Fahrzeug::vAusgeben(ostream& out) const {//6.
 out << setw(5) << p_iID << setw(10) << p_sName << setw(22) << fixed << setprecision(2) <<  p_dMaxGeschwindigkeit << setw(17) << fixed << setprecision(2) << p_dGesamtStrecke <<setw(19)<< fixed << setprecision(2) <<  p_dGeschwindigkeit ; //setw setzt die width wie genau die formartierung ist durch ausprobieren
//set hält n platz für etwas frei
}
void Fahrzeug::vKopf(){
 cout << setw(5) << "p_iID" << setw(10) << "p_sName" << setw(15) << " p_dMaxGeschwindigkeit" << setw(15) << " p_dGesamtStrecke"<< setw(15) << " p_dGeschwindigkeit" << setw(20) << " Gesamtverbrauch " << setw(20)<< setprecision(2) << "Aktueller Tankinhalt "<< endl;
 cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;

}
void Fahrzeug::vSimulieren(){//8.
 double zeitDelta=p_dGlobalezeit-p_dZeit;
 if(zeitDelta!=0){
	 p_dGesamtStrecke=p_dGesamtStrecke+(p_dGeschwindigkeit *zeitDelta);
	 p_dGesamtzeit=p_dGesamtzeit+zeitDelta;
	 p_dZeit=p_dGlobalezeit;
 }

}
 double Fahrzeug::dTanken(){
	 return 0;
 }

 double Fahrzeug::dTanken(double dMenge) {
     // Fahrzeuge ohne Tank tanken nichts
     return 0.0;

 }
   double Fahrzeug::dGeschwindigkeit(){
    return p_dMaxGeschwindigkeit;
  }
