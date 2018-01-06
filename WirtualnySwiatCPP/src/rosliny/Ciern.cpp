/*
 * Ciern.cpp
 *
 *  Created on: 03.01.2018
 *      Author: Szymon
 */
#include "Ciern.h"
#include "../Swiat.h"

namespace roslina {

Ciern::Ciern(int x, int y) {
	this->x = x;
	this->y = y;
	sila = 2;
	symbol = 'c';
}

Ciern::~Ciern() {
    world->logger.push_back("Ciern zjedzony");
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
	}
	else if ((kierunek == 1) && (x < wymiar - 1)) {
		//ruch w prawo
		tmp_x += 1;
	}
	else if ((kierunek == 2) && (y < wymiar - 1)) {
		//ruch w dol
		tmp_y += 1;
	}
	else if ((kierunek == 3) && (x > 0)) {
		//ruch w lewo
		tmp_x -= 1;
	}

	if (naMapie[tmp_x][tmp_y] == nullptr) {
		rozmnazanie(tmp_x, tmp_y);
	}
}

void Ciern::rozmnazanie(int newX, int newY) {

    naMapie[newX][newY] = new Ciern(newX, newY);
    naMapie[newX][newY]->setSwiat(*world);
    world->organizmy.push_back(naMapie[newX][newY]);
    world->logger.push_back("Ciern narodziny (rozmnozenie)");

}

}

