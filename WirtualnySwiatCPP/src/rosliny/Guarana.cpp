/*
 * Guarana.cpp
 *
 *  Created on: 03.01.2018
 *      Author: Szymon
 */

#include "Guarana.h"
#include "../Swiat.h"

namespace roslina {

Guarana::Guarana(int x, int y) {
	this->x = x;
	this->y = y;
	symbol = 'g';
}

Guarana::~Guarana() {
	world->logger.push_back("Guarana zjedzona");
}

void Guarana::rozmnazanie(int newX, int newY) {
	naMapie[newX][newY] = new Guarana(newX, newY);
	naMapie[newX][newY]->setSwiat(*world);
	world->organizmy.push_back(naMapie[newX][newY]);
	world->logger.push_back("Narodziny-(rozmnozenie) Guarany");
}

void Guarana::kolizja(organizm::Organizm* oponent) {
	int tmp_sila = oponent->getSila();
	std::string komunikat;
	if (sila > tmp_sila) {
		oponent->setAlive(false);
		world->logger.push_back("Guarana wygrala pojedynek z: ");
	}
	else if (sila < tmp_sila) {
		setAlive(false);
		// po jej zjedzeniu zwieksza sile oponeta o 3
		oponent->setSila(3);
		world->logger.push_back("Guarana zwiekszyla sile o 3 dla: ");
	}
}

}


