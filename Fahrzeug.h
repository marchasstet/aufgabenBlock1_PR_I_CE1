/*
 * Fahrzeug.h
 *
 *  Created on: 02.11.2023
 *      Author: marcd
 */
#include <iostream>
#include <iomanip>
#include<limits>
#include <string>
#include "GlobaleUhr.h"
#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_


using namespace std;
class Fahrzeug {
//	friend bool operator<(const Fahrzeug& fahrzeug1, const Fahrzeug& fahrzeug2) {
//	        return fahrzeug1.p_dGesamtStrecke < fahrzeug2.p_dGesamtStrecke;}
//

private:
    //welches besser?
	static inline int p_iMaxID=0;
     //Gesamte Fahrzeit des Fahrzeuges


protected:
    const int p_iID=p_iMaxID;
    std:: string p_sName="";
    double p_dMaxGeschwindigkeit=0.00;
    double p_dGesamtStrecke=0.00;
    double p_dZeit=0.00; //Zeit zu der das Fahrzeug zuletz simuliert wurde
    double p_dGeschwindigkeit=p_dMaxGeschwindigkeit;
    double p_dGesamtzeit=0.00;

public:
    Fahrzeug( string sName);
    Fahrzeug(string sName,double dMaxGeschwindigkeit);
    Fahrzeug();
    Fahrzeug(const Fahrzeug&) = delete;
     bool operator<(const Fahrzeug& other) const {
    	  if((p_dGesamtStrecke< other.p_dGesamtStrecke)==true){cout<<"true\n";return true;}
    	      cout<<"false\n"; return  false;}
     Fahrzeug& operator=(const Fahrzeug& other) {
            // Nur Stammdaten kopieren
    	 p_dGesamtStrecke = other.p_dGesamtStrecke;
    	 p_sName=other.p_sName;
    	 p_dMaxGeschwindigkeit=other.p_dMaxGeschwindigkeit;

            return *this;
     }
    virtual void vAusgeben(ostream&) const;
    static void vKopf();
    virtual ~Fahrzeug();
    virtual void vSimulieren();

    virtual double dTanken();
    virtual double dTanken(double dMenge);
    virtual  double dGeschwindigkeit();
    string getName(){

    	return p_sName;
    }
};

#endif /* FAHRZEUG_H_ */

