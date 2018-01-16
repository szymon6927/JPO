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
#include <memory>
#include <array>
#include <string>
#include "Organizm.h"

#ifndef SWIAT_H_
#define SWIAT_H_

class Swiat {
private:
	static bool sortowanie(organizm::Organizm* i, organizm::Organizm* j);
	static bool sortowanieZywych(organizm::Organizm* i, organizm::Organizm* j);

	static const int wielkoscSwiata = 20;
public:
	std::array<std::array<std::unique_ptr<organizm::Organizm>, wielkoscSwiata>, wielkoscSwiata> mapaOrganizmow;
	std::vector<organizm::Organizm*> organizmy;
	std::vector<std::string> logger;

	char** mapa;
	void wykonajTure();
	void rysujSwiat();
	void utworzSwiat();
	std::string zachowajSwiat() const;
	void inputParser(int argc, char** argv);
	Swiat();
	~Swiat();
};

#endif /* SWIAT_H_ */
