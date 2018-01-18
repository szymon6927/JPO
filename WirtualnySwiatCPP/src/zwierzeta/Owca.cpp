/*
 * Owca.cpp
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */

#include "Owca.h"
#include "../Swiat.h"

namespace zwierze {

Owca::Owca(Swiat& swiat, int x, int y) :
		Zwierze(swiat, 4, 4, x, y) {
}

Owca::~Owca() {
	swiat.logger.push_back("Owca umiera!");
}

void Owca::rozmnazanie(Organizm& partner) {

	int tx = partner.getX();
	int ty = partner.getY();
	int j = 0;
	bool miejsceWgospodzie = false;

	int nx[] = { x, x, x + 1, x - 1, tx, tx, tx + 1, tx - 1 };
	int ny[] = { y + 1, y - 1, y, y, ty + 1, ty - 1, ty, ty };

	for (; j < 8; j++) {
		if (nx[j] >= 0 && nx[j] < 20 && ny[j] >= 0 && ny[j] < 20 && swiat.znajdzOrganizmPoPozycji(nx[j], ny[j]) == nullptr) {
			miejsceWgospodzie = true;
			break;
		}
	}

	if (miejsceWgospodzie) {
		swiat.dodajOrganizm<Owca>(nx[j], ny[j], "Narodziny Owcy-(rozmnozenie)");
	}
}

char Owca::getSymbol() const {
	return 'O';
}

}

