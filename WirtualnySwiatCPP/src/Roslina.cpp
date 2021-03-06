/*
 * Roslina.cpp
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */

#include "Roslina.h"

namespace roslina {

Roslina::Roslina() {
	inicjatywa = 0;
	sila = 0;
}

Roslina::~Roslina() {

}

void Roslina::akcja() {
	//zwykle poruszanie sie
	int wylosowaneRozplenianie = rand() % 99;

	if (wylosowaneRozplenianie < 10) {

		int kierunek = rand() % 4;
		const int wymiar = 20;

		int tmp_x = x;
		int tmp_y = y;

		if ((kierunek == 0) && (y > 0)) {
			//ruch w gore
			tmp_y -= 1;
		} else if ((kierunek == 1) && (x < wymiar - 1)) {
			//ruch w prawo
			tmp_x += 1;
		} else if ((kierunek == 2) && (y < wymiar - 1)) {
			//ruch w dol
			tmp_y += 1;
		} else if ((kierunek == 3) && (x > 0)) {
			//ruch w lewo
			tmp_x -= 1;
		}

		if (naMapie[tmp_x][tmp_y] == nullptr) {
			rozmnazanie(tmp_x, tmp_y);
		}
	}
}

void Roslina::kolizja(organizm::Organizm* oponent) {
	//jezeli zwierzaki te same = rozmnazanie
	int tmp_sila = oponent->getSila();

	if (sila > tmp_sila) {
		oponent->setAlive(false);
	} else if (sila < tmp_sila) {
		setAlive(false);
	}

}

void Roslina::rozmnazanie(organizm::Organizm* partner) {
	//dummy
}

}

