/*
 * Hipopotam.cpp
 *
 *  Created on: 04.01.2018
 *      Author: Szymon
 */

#include "Hipopotam.h"
#include "../Swiat.h"

namespace zwierze {

Hipopotam::Hipopotam(int x, int y) {
	this->x = x;
	this->y = y;
	inicjatywa = 50;
	sila = 40;
	symbol = 'H';
}

Hipopotam::~Hipopotam() {
	world->logger.push_back("Najslinijeszy z zwierzat umiera !!! :(");
}

void Hipopotam::rozmnazanie(Organizm* partner) {
	for (int i = 0; i < 2; i++) {
		int tx = partner->getX();
		int ty = partner->getY();
		int j = 0;
		bool miejsceWgospodzie = false;

		int nx[] = { x, x, x + 1, x - 1, tx, tx, tx + 1, tx - 1 };
		int ny[] = { y + 1, y - 1, y, y, ty + 1, ty - 1, ty, ty };

		for (; j < 8; j++) {
			if (nx[j] >= 0 && nx[j] < 20 && ny[j] >= 0 && ny[j] < 20
					&& naMapie[nx[j]][ny[j]] == nullptr) {
				miejsceWgospodzie = true;
				break;
			}
		}

		if (miejsceWgospodzie) {
			naMapie[nx[j]][ny[j]] = new Hipopotam(nx[j], ny[j]);
			naMapie[nx[j]][ny[j]]->setSwiat(*world);
			world->organizmy.push_back(naMapie[nx[j]][ny[j]]);
			world->logger.push_back(
					"Narodziny Hipopotama - najwiekszego kozaka w wirtualnym Swiecie!");
		}
	}
}

}

