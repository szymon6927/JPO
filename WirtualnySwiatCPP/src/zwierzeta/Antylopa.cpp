/*
 * Antylopa.cpp
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */

//#include <string>
#include "Antylopa.h"
#include "../Swiat.h"

namespace zwierze {

Antylopa::Antylopa(int x, int y) {
	this->x = x;
	this->y = y;
	inicjatywa = 4;
	sila = 4;
	symbol = 'A';
}

Antylopa::~Antylopa() {
	world->logger.push_back("Antylopa umarla!");
}

void Antylopa::akcja() {
	// zasieg ruchu antylopy to dwa pola
	int kierunek = rand() % 4;
	const int wymiar = 20;

	int tmp_x = x;
	int tmp_y = y;

	if ((kierunek == 0) && (y > 2)) {
		//ruch w gore o 2
		tmp_y -= 2;
	}
	else if ((kierunek == 1) && (x < wymiar - 2)) {
		//ruch w prawo o 2
		tmp_x += 2;
	}
	else if ((kierunek == 2) && (y < wymiar - 2)) {
		//ruch w dol o 2
		tmp_y += 2;
	}
	else if ((kierunek == 3) && (x > 2)) {
		//ruch w lewo o 2
		tmp_x -= 2;
	}

	if (naMapie[tmp_x][tmp_y] == nullptr) {
		naMapie[tmp_x][tmp_y] = naMapie[x][y];
		naMapie[x][y] = nullptr;
		x = tmp_x;
		y = tmp_y;
	}
	else if (naMapie[tmp_x][tmp_y]->getSymbol() == symbol && naMapie[tmp_x][tmp_y] != &*this) {
		rozmnazanie(naMapie[tmp_x][tmp_y]); //sprawdz to
	}
	else if (naMapie[tmp_x][tmp_y] != &*this) {

		naMapie[tmp_x][tmp_y]->kolizja(&*this);
		kolizja(naMapie[tmp_x][tmp_y]);

		if (isAlive()) {
			naMapie[tmp_x][tmp_y] = naMapie[x][y];
			naMapie[x][y] = nullptr;
			x = tmp_x;
			y = tmp_y;
		}
		else {
			naMapie[x][y] = nullptr;
		}
	}
}

void Antylopa::kolizja(organizm::Organizm* oponent) {
	int szansaUcieczki = rand() % 2; // daje mi 0 albo 1
	std::string komunikat;
	if (szansaUcieczki==0) {
		komunikat = "Antylopa ucieka w walce z: ";
		world->logger.push_back(komunikat += oponent->getSymbol());
		this->akcja();
	}
	else {
		int tmp_sila = oponent->getSila();
		if (sila > tmp_sila) {
			oponent->setAlive(false);
			komunikat = "Antylopa wygrywa z: ";
			world->logger.push_back(komunikat += oponent->getSymbol());
		}
		else if (sila < tmp_sila) {
			setAlive(false);
			komunikat = "Antylopa przegrywa z: ";
			world->logger.push_back(komunikat += oponent->getSymbol());
		}
		else if (alive) {
			setAlive(false);
			komunikat = "Antylopa przegrywa bo pierwszy zaatakowal: ";
			world->logger.push_back(komunikat += oponent->getSymbol());
		}
	}
}

void Antylopa::rozmnazanie(organizm::Organizm* partner) {
	int tx = partner->getX();
	int ty = partner->getY();
	int j = 0;
	bool miejsceWgospodzie = false;

	int nx[] = {    x,     x, x + 1, x - 1,     tx,     tx, tx + 1, tx - 1};
	int ny[] = {y + 1, y - 1,     y,     y, ty + 1, ty - 1,     ty,     ty};

	for ( ; j < 8; j++ ) {
		if (nx[j] >= 0 && nx[j] < 20 &&
			ny[j] >= 0 && ny[j] < 20 &&
			naMapie[nx[j]][ny[j]] == nullptr) {
			miejsceWgospodzie = true;
			break;
		}
	}

	if (miejsceWgospodzie) {
		naMapie[nx[j]][ny[j]] = new Antylopa(nx[j], ny[j]);
		naMapie[nx[j]][ny[j]]->setSwiat(*world);
		world->organizmy.push_back(naMapie[nx[j]][ny[j]]);
		world->logger.push_back("Narodziny Antylopy-(rozmnozenie)");
	}
}

}


