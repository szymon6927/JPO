/*
 * Leniwiec.cpp
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */

#include "Leniwiec.h"
#include "../Swiat.h"

namespace zwierze {
Leniwiec::Leniwiec(Swiat& swiat, int x, int y) :
		Zwierze(swiat, 2, 1, x, y) {
}
Leniwiec::~Leniwiec() {
	swiat.logger.push_back("Umarl leniwiec!");
}

void Leniwiec::akcja() {
	iloscRuchow++;
	if (iloscRuchow < 2) { // na ruchy na ture
		int wylosowaneCzolganie = rand() % 100;

		if (wylosowaneCzolganie < 25) {

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

			if (swiat.znajdzOrganizmPoPozycji(tmp_x, tmp_y) == nullptr) {
				swiat.zamienMiejscami(x, y, tmp_x, tmp_y);
			}
			else if (swiat.znajdzOrganizmPoPozycji(tmp_x, tmp_y)->getSymbol() == getSymbol()) {
				rozmnazanie(*swiat.znajdzOrganizmPoPozycji(tmp_x, tmp_y)); //sprawdz to
			}
			else if (swiat.znajdzOrganizmPoPozycji(tmp_x, tmp_y) != this) {
				kolizja(*swiat.znajdzOrganizmPoPozycji(tmp_x, tmp_y));
				if (czyZywy()) {
					swiat.zamienMiejscami(x, y, tmp_x, tmp_y);
				}
			}
		}
	}
	else {
		iloscRuchow = 0;
	}
}

void Leniwiec::rozmnazanie(Organizm& partner) {

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
		swiat.dodajOrganizm<Leniwiec>(nx[j], ny[j], "Narodziny Leniwca-(rozmnozenie)");
	}

}

char Leniwiec::getSymbol() const {
	return 'L';
}

}

