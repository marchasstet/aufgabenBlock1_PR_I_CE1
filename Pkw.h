/*
 * Pkw.h
 *
 *  Created on: 24.11.2023
 *      Author: marcd
 */
#include "Fahrzeug.h"
#include "GlobaleUhr.h"
#include <iostream>
#include <string>
#include <iomanip>
#include<limits>
using namespace std;
#ifndef PKW_H_
#define PKW_H_

class Pkw: public Fahrzeug{//pkw erbt von Fahrzeug

private:
double p_dVerbrauch;          // Liter/100km
double p_dTankvolumen=55;        // Liter wie viel passt in den Tank
double p_dTankinhalt=p_dTankvolumen/2;
double p_dGesamtVerbrauch=0;// Liter aktueller tankinhalt
public:
	Pkw();

	Pkw(std::string sName, double p_dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen=55);

	virtual ~Pkw() override;
	virtual void vAusgeben(ostream& out) const override;
	virtual void vSimulieren() override;
	double dTanken(double dMenge )  override;// müsste eig overrride sein aber funktioniert nich
    virtual  double dGeschwindigkeit() override {

    	return 0;
    };
    double dTanken() override ;
};

#endif /* PKW_H_ */
