/*
 * Ciern.cpp
 *
 *  Created on: 03.01.2018
 *      Author: Szymon
 */
#include "Ciern.h"
#include "../Swiat.h"

namespace roslina {

Ciern::Ciern(Swiat& swiat, int x, int y) :
		Roslina(swiat, 2, x, y) {
}

Ciern::~Ciern() {
	swiat.logger.push_back("Ciern zjedzony");
}

void Ciern::akcja() {
	//zawsze sukces
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
		rozmnazanie(tmp_x, tmp_y);
	}
}

void Ciern::rozmnazanie(int newX, int newY) {
	swiat.mapaOrganizmow[newX][newY] = std::make_unique<Ciern>(swiat, newX, newY);
	swiat.organizmy.push_back(swiat.mapaOrganizmow[newX][newY].get());
	swiat.logger.push_back("Ciern narodziny (rozmnozenie)");
}

char Ciern::getSymbol() const {
	return 'c';
}

}

