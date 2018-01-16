/*
 *  * Trawa.cpp
 *
 *  Created on: 03.01.2018
 *      Author: Szymon
 */

#include "Trawa.h"
#include "../Swiat.h"

namespace roslina {

Trawa::Trawa(Swiat& swiat, int x, int y) :
		Roslina(swiat, 0, x, y) {
}

Trawa::~Trawa() {
	swiat.logger.push_back("Trawa zjedzona");
}

void Trawa::rozmnazanie(int newX, int newY) {
	swiat.dodajOrganizm<Trawa>(newX, newY, "Narodziny nudnej Trawy");
}

char Trawa::getSymbol() const {
	return 'g';
}

}

