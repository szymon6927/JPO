/*
 * Swiat.h
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include "Organizm.h"

#ifndef SWIAT_H_
#define SWIAT_H_

class Swiat {
private:
	static bool sortowanie(organizm::Organizm* i, organizm::Organizm* j);
	static bool sortowanieZywych(organizm::Organizm* i, organizm::Organizm* j);
public:
	organizm::Organizm*** mapaOrganizmow;
	std::vector<organizm::Organizm*> organizmy;
	std::vector<std::string> logger;

	char** mapa;
	void wykonajTure();
	void rysujSwiat();
	void utworzSwiat();
	std::string zachowajSwiat();
	Swiat();
	~Swiat();
};

#endif /* SWIAT_H_ */
