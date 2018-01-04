/*
 *  * Trawa.cpp
 *
 *  Created on: 03.01.2018
 *      Author: Szymon
 */

#include "Trawa.h"
#include "../Swiat.h"

namespace roslina {

Trawa::Trawa(int x, int y) {
	this->x = x;
	this->y = y;
	symbol = 't';
}

Trawa::~Trawa() {
	world->logger.push_back("Trawa zjedzona");
}

void Trawa::rozmnazanie(int newX, int newY) {
	naMapie[newX][newY] = new Trawa(newX, newY);
	naMapie[newX][newY]->setSwiat(*world);
	world->organizmy.push_back(naMapie[newX][newY]);
	world->logger.push_back("Narodziny nudnej Trawy");
}

}




