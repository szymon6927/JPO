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

Antylopa::Antylopa(Swiat& swiat, int x, int y) : Zwierze(swiat, 4, 4, x, y) {}

Antylopa::~Antylopa() {
	swiat.logger.push_back("Antylopa umarla!");
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

	if (swiat.mapaOrganizmow[tmp_x][tmp_y] == nullptr) {
		swiat.mapaOrganizmow[tmp_x][tmp_y] = swiat.mapaOrganizmow[x][y];
		swiat.mapaOrganizmow[x][y] = nullptr;
		x = tmp_x;
		y = tmp_y;
	}
	else if (swiat.mapaOrganizmow[tmp_x][tmp_y]->getSymbol() == getSymbol() && swiat.mapaOrganizmow[tmp_x][tmp_y] != &*this) {
		rozmnazanie(swiat.mapaOrganizmow[tmp_x][tmp_y]); //sprawdz to
	}
	else if (swiat.mapaOrganizmow[tmp_x][tmp_y] != &*this) {

		swiat.mapaOrganizmow[tmp_x][tmp_y]->kolizja(&*this);
		kolizja(swiat.mapaOrganizmow[tmp_x][tmp_y]);

		if (czyZywy()) {
			swiat.mapaOrganizmow[tmp_x][tmp_y] = swiat.mapaOrganizmow[x][y];
			swiat.mapaOrganizmow[x][y] = nullptr;
			x = tmp_x;
			y = tmp_y;
		}
		else {
			swiat.mapaOrganizmow[x][y] = nullptr;
		}
	}
}

void Antylopa::kolizja(organizm::Organizm* oponent) {
	int szansaUcieczki = rand() % 2; // daje mi 0 albo 1
	std::string komunikat;
	if (szansaUcieczki==0) {
		komunikat = "Antylopa ucieka w walce z: ";
		swiat.logger.push_back(komunikat += oponent->getSymbol());
		this->akcja();
	}
	else {
		int tmp_sila = oponent->getSila();
		if (sila > tmp_sila) {
			oponent->setAlive(false);
			komunikat = "Antylopa wygrywa z: ";
			swiat.logger.push_back(komunikat += oponent->getSymbol());
		}
		else if (sila < tmp_sila) {
			setAlive(false);
			komunikat = "Antylopa przegrywa z: ";
			swiat.logger.push_back(komunikat += oponent->getSymbol());
		}
		else if (alive) {
			setAlive(false);
			komunikat = "Antylopa przegrywa bo pierwszy zaatakowal: ";
			swiat.logger.push_back(komunikat += oponent->getSymbol());
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
			swiat.mapaOrganizmow[nx[j]][ny[j]] == nullptr) {
			miejsceWgospodzie = true;
			break;
		}
	}

	if (miejsceWgospodzie) {
		swiat.mapaOrganizmow[nx[j]][ny[j]] = new Antylopa(swiat ,nx[j], ny[j]);
		swiat.organizmy.push_back(swiat.mapaOrganizmow[nx[j]][ny[j]]);
		swiat.logger.push_back("Narodziny Antylopy-(rozmnozenie)");
	}
}

char Antylopa::getSymbol() const {
	return 'A';
}

}

