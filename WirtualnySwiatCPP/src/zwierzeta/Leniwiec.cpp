/*
 * Leniwiec.cpp
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */

#include "Leniwiec.h"
#include "../Swiat.h"

namespace zwierze {
	Leniwiec::Leniwiec(int x, int y) {
		this->x = x;
		this->y = y;
		inicjatywa = 1;
		sila = 2;
		symbol = 'L';
		poprzedniWiek = this->getWiek(); //wiek mowi nam czy faktycznie leniwiec poryszyl sie raz na ture poniewaz co ture wiek sie zwiekszany o 1
	}
	Leniwiec::~Leniwiec() {
		world->logger.push_back("Umarl leniwiec!");
	}

	void Leniwiec::akcja() {
		if(this->getWiek() == poprzedniWiek) {
			Zwierze::akcja();
		}
	}

	void Leniwiec::rozmnazanie(organizm::Organizm* partner) {

	    int tx = partner->getX();
	    int ty = partner->getY();
	    int j = 0;
	    bool miejsceWgospodzie = false;

	    int nx[] = {    x,     x, x + 1, x - 1,     tx,     tx, tx + 1, tx - 1};
	    int ny[] = {y + 1, y - 1,     y,     y, ty + 1, ty - 1,     ty,     ty};

	    for (unsigned j; j < 8; j++ ) {
	        if (nx[j] >= 0 && nx[j] < 20 &&
	            ny[j] >= 0 && ny[j] < 20 &&
	            naMapie[nx[j]][ny[j]] == nullptr) {
	            miejsceWgospodzie = true;
	            break;
	        }
	    }

	    if (miejsceWgospodzie) {
	        naMapie[nx[j]][ny[j]] = new Leniwiec(nx[j], ny[j]);
	        naMapie[nx[j]][ny[j]]->setSwiat(*world);
	        world->organizmy.push_back(naMapie[nx[j]][ny[j]]);
	        world->logger.push_back("Narodziny Leniwca");
	    }

	}
}



