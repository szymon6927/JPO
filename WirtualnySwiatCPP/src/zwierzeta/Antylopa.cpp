/*
 * Antylopa.cpp
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */

namespace zwierze {

Antylopa::Antylopa(int x, int y) {
	this->x = x;
	this->y = y;
	inicjatywa = 4;
	sila = 4;
	symbol = 'A';
}

Antylopa::~Antylopa() {
	world->logger("Antylopa umarla!");
}

void Antylopa::akcja() {

}

}


