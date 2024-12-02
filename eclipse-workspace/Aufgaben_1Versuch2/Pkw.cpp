/*
 * Pkw.cpp
 *
 *  Created on: 24.11.2023
 *      Author: marcd
 */

#include "Pkw.h"
//#include "Fahrzeug.h"
#include "GlobaleUhr.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>

using namespace std;



Pkw::Pkw(std::string sName, double p_dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen)
	    : Fahrzeug(sName, p_dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(dTankvolumen) {
	    p_dTankinhalt = dTankvolumen / 2.0; // initoalisierung mit halben tank volumen
	}

Pkw::~Pkw() {
	// TODO Auto-generated destructor stub
}

void Pkw::vAusgeben(ostream& out) const { //spezifischer vAusgeben für Pkw  4.3.1

    Fahrzeug::vAusgeben(out); // @suppress("Invalid arguments")
    out << setprecision(2)<<setw(13) << p_dGesamtVerbrauch<< " Liter"  << setprecision(2)<<setw(15)<<p_dTankinhalt << " Liter" << endl;
}

void Pkw::vSimulieren() {//spezifischer vSimulieren für Pkw  4.3.1

//
 // Fahrzeug::vSimulieren();
//
//        // Implement additional PKW-specific functionality
//        if (p_dTankinhalt <= 0.0) {
//            // PKW is out of fuel, cannot simulate further
//        	p_dGeschwindigkeit=0;
//
//        } else {
//            // Continue simulation for PKW with remaining fuel
//            p_dTankinhalt = p_dTankinhalt-(p_dVerbrauch);
//
//            // If the tank is empty after the simulation step, print a message
//            if (p_dTankinhalt <= 0.0) {
//
//                p_dTankinhalt = 0.0;  // Ensure tank is not negative
//                p_dGeschwindigkeit=0;
//            }
//        }
	//
	double zeitDelta=p_dGlobalezeit-p_dZeit;
	 if(zeitDelta > 0.0 && (p_dTankinhalt > 0)){
		 double zuruckgelegteStrecke=(p_dGeschwindigkeit *zeitDelta);
		 double dtempVerbrauch=(zuruckgelegteStrecke/100)*p_dVerbrauch;
//		 if(p_dTankinhalt-dtempVerbrauch>0){
		 p_dGesamtzeit+=zeitDelta;
		 p_dGesamtStrecke=p_dGesamtStrecke+(p_dGeschwindigkeit *zeitDelta);
		 p_dTankinhalt -= dtempVerbrauch;
		 p_dGesamtVerbrauch += (zuruckgelegteStrecke/100)*p_dVerbrauch;
		 p_dZeit = p_dGlobalezeit;
		 }
//		 else{
//			 p_dGesamtzeit+=zeitDelta;
//			 double temp=p_dTankinhalt-dtempVerbrauch;
//			p_dTankinhalt+= dtempVerbrauch-temp;
//			p_dGesamtVerbrauch=(dtempVerbrauch-temp);
//			p_dGesamtStrecke=p_dGesamtStrecke+(p_dGeschwindigkeit *zeitDelta);
//
//		 }

	 else{ p_dZeit = p_dGlobalezeit;}
	 if(p_dTankinhalt <= 0){
	         p_dTankinhalt = 0;
	         p_dGesamtStrecke +=0;
	         p_dGesamtVerbrauch +=0;

	     }

}

double Pkw::dTanken(){

	 double maxRefuel = Pkw::p_dTankvolumen- Pkw::p_dTankinhalt;

	p_dTankinhalt += maxRefuel;
return maxRefuel;
}
double Pkw::dTanken(double dMenge) {
    if (dMenge < 0.0) {


        dMenge=0;
    }
    double maxRefuel = p_dTankvolumen - p_dTankinhalt;
        double actualRefuel = min(dMenge, maxRefuel);// min(x,y) vergleicht die größe von x und y und gibt den kleineren inhalt zurück dadurch wird geguck dass maxmal der tank rand voll gefüllt wird, theorethisch evtl über die if funktion möglich

        p_dTankinhalt += actualRefuel;

        return actualRefuel;
}

