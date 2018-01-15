/*
 * Guarana.cpp
 *
 *  Created on: 03.01.2018
 *      Author: Szymon
 */

#include "Guarana.h"
#include "../Swiat.h"

namespace roslina {

Guarana::Guarana(Swiat& swiat, int x, int y) :
		Roslina(swiat, 0, x, y) {
}

Guarana::~Guarana() {
	swiat.logger.push_back("Guarana zjedzona");
}

void Guarana::rozmnazanie(int newX, int newY) {
	swiat.mapaOrganizmow[newX][newY] = new Guarana(swiat, newX, newY);
	swiat.organizmy.push_back(swiat.mapaOrganizmow[newX][newY]);
	swiat.logger.push_back("Narodziny-(rozmnozenie) Guarany");
}

void Guarana::kolizja(organizm::Organizm* oponent) {
	int tmp_sila = oponent->getSila();
	std::string komunikat;
	if (sila > tmp_sila) {
		oponent->setAlive(false);
		komunikat = "Guarana wygrala pojedynek z: ";
		swiat.logger.push_back(komunikat += oponent->getSymbol());
	} else if (sila < tmp_sila) {
		setAlive(false);
		// po jej zjedzeniu zwieksza sile oponeta o 3
		oponent->zwiekszSile(+3);
		komunikat = "Guarana zwiekszyla sile o 3 dla: ";
		swiat.logger.push_back(komunikat += oponent->getSymbol());
	}
}

char Guarana::getSymbol() const {
	return 'g';
}

}

