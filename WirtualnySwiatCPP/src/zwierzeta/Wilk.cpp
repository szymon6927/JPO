/*
 * Wilk.cpp
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */

#include "Wilk.h"
#include "../Swiat.h" //bez tego blad kompilacji :/

namespace zwierze {

Wilk::Wilk(Swiat& swiat, int x, int y) :
		Zwierze(swiat, 9, 5, x, y) {
}

Wilk::~Wilk() {
	swiat.logger.push_back("Wilk padl!");
}

void Wilk::rozmnazanie(Organizm& partner) {

	int tx = partner.getX();
	int ty = partner.getY();
	int j = 0;
	bool miejsceWgospodzie = false;

	int nx[] = { x, x, x + 1, x - 1, tx, tx, tx + 1, tx - 1 };
	int ny[] = { y + 1, y - 1, y, y, ty + 1, ty - 1, ty, ty };

	for (unsigned j; j < 8; j++) {
		if (nx[j] >= 0 && nx[j] < 20 && ny[j] >= 0 && ny[j] < 20 && swiat.znajdzOrganizmPoPozycji(nx[j], ny[j]) == nullptr) {
			miejsceWgospodzie = true;
			break;
		}
	}

	if (miejsceWgospodzie) {
		swiat.dodajOrganizm<Wilk>(nx[j], ny[j], "Narodziny Wilka-(rozmnozenie)");
	}

}

char Wilk::getSymbol() const {
	return 'W';
}

}

