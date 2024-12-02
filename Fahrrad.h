/*
 * Fahrrad.h
 *
 *  Created on: 24.11.2023
 *      Author: marcd
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_
//#include "Fahrrad.h"
#include "Fahrzeug.h"
#include "GlobaleUhr.h"
#include <iostream>
#include <string>
#include <iomanip>
class Fahrrad : public Fahrzeug {


public:
	Fahrrad();
	Fahrrad(std::string sName, double dMaxGeschwindigkeit);
	virtual ~Fahrrad() override;
	virtual void vAusgeben(ostream& out) const override;
    virtual void vSimulieren() override;
    virtual double dGeschwindigkeit() override ;

};

#endif /* FAHRRAD_H_ */
