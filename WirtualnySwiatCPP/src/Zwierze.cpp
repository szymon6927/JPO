/*
 * Zwierze.cpp
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */
#include "Swiat.h"
#include "Zwierze.h"

namespace zwierze {

Zwierze::Zwierze(Swiat& swiat, int sila, int inicjatywa, int x, int y) :
		Organizm(swiat, sila, inicjatywa, x, y) {
}

void Zwierze::akcja() {
	//zwykle poruszanie sie
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

	if (swiat.mapaOrganizmow[tmp_x][tmp_y] == nullptr) {
		swiat.mapaOrganizmow[tmp_x][tmp_y] = swiat.mapaOrganizmow[x][y];
		swiat.mapaOrganizmow[x][y] = nullptr;
		x = tmp_x;
		y = tmp_y;
	} else if (swiat.mapaOrganizmow[tmp_x][tmp_y]->getSymbol() == getSymbol()
			&& swiat.mapaOrganizmow[tmp_x][tmp_y] != this) {
		rozmnazanie(swiat.mapaOrganizmow[tmp_x][tmp_y]);
	} else if (swiat.mapaOrganizmow[tmp_x][tmp_y] != this) {
		swiat.mapaOrganizmow[tmp_x][tmp_y]->kolizja(this);
		kolizja(swiat.mapaOrganizmow[tmp_x][tmp_y]);
		if (czyZywy()) {
			swiat.mapaOrganizmow[tmp_x][tmp_y] = swiat.mapaOrganizmow[x][y];
			swiat.mapaOrganizmow[x][y] = nullptr;
			x = tmp_x;
			y = tmp_y;
		} else if (!czyZywy()) {
			swiat.mapaOrganizmow[x][y] = nullptr;
		}
	}
}

void Zwierze::kolizja(organizm::Organizm* oponent) {
	//jezeli zwierzaki te same = rozmnazanie
	int tmp_sila = oponent->getSila();

	if (sila > tmp_sila) {
		oponent->setAlive(false);
	} else if (sila < tmp_sila) {
		setAlive(false);
	} else if (alive) {
		setAlive(false);
	}

}

void Zwierze::rozmnazanie(int newX, int newY) {
	//dummy
}

}
