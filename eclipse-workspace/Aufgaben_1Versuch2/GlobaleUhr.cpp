/*
 * GlobaleUhr.cpp
 *
 *  Created on: 22.11.2023
 *      Author: marcd
 */

#include "GlobaleUhr.h"
#include <chrono>

double p_dGlobalezeit = 0.0;

void vAktualisiereUhr(double dInkrement) {

    p_dGlobalezeit += dInkrement;
}
