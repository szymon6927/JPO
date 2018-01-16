/*
 * Hipopotam.cpp
 *
 *  Created on: 04.01.2018
 *      Author: Szymon
 */

#include "Hipopotam.h"
#include "../Swiat.h"

namespace zwierze {

Hipopotam::Hipopotam(Swiat& swiat, int x, int y) :
		Zwierze(swiat, 40, 50, x, y) {
}

Hipopotam::~Hipopotam() {
	swiat.logger.push_back("Najslinijeszy z zwierzat umiera !!! :(");
}

void Hipopotam::rozmnazanie(Organizm& partner) {
	for (int i = 0; i < 2; i++) {
		int tx = partner.getX();
		int ty = partner.getY();
		int j = 0;
		bool miejsceWgospodzie = false;

		int nx[] = { x, x, x + 1, x - 1, tx, tx, tx + 1, tx - 1 };
		int ny[] = { y + 1, y - 1, y, y, ty + 1, ty - 1, ty, ty };

		for (; j < 8; j++) {
			if (nx[j] >= 0 && nx[j] < 20 && ny[j] >= 0 && ny[j] < 20
					&& swiat.mapaOrganizmow[nx[j]][ny[j]] == nullptr) {
				miejsceWgospodzie = true;
				break;
			}
		}

		if (miejsceWgospodzie) {
			swiat.dodajOrganizm<Hipopotam>(nx[j], ny[j], "Narodziny Hipopotama - najwiekszego kozaaka!");
		}
	}
}

char Hipopotam::getSymbol() const {
	return 'H';
}

}

