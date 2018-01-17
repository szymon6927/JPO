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
#include <type_traits>
#include "Organizm.h"

#ifndef SWIAT_H_
#define SWIAT_H_

class Swiat {
private:
	static bool sortowanie(Organizm* i, Organizm* j);

	static const int wielkoscSwiata = 20;

	std::array<std::array<std::unique_ptr<Organizm>, wielkoscSwiata>, wielkoscSwiata> mapaOrganizmow;
	std::vector<Organizm*> organizmy;
public:
	Organizm* znajdzOrganizmPoPozycji(int x, int y);

	/**
	 * @details pole (x1,y1) musi byc zajête, pole (x1, y2) mo¿e byc puste
	 */
	void zamienMiejscami(int x1, int y1, int x2, int y2) noexcept; // move ctor zawsze noexcept (przezuca tylko pointery) ~ silna konwecja

	std::vector<std::string> logger;

	void wykonajTure();
	void rysujSwiat();
	void utworzSwiat();
	std::string zachowajSwiat() const;
	void inputParser(int argc, char** argv);

	template<typename T> // typ organizmu
	void dodajOrganizm(int x, int y, const std::string& logger);

	Swiat();
	~Swiat();
};

template<typename T>
void Swiat::dodajOrganizm(int x, int y, const std::string& log) {
	static_assert(std::is_base_of<Organizm, T>::value, "Nie prawidlowy typ T, musi byc organizmem");

	mapaOrganizmow[x][y] = std::make_unique<T>(*this, x, y);
	organizmy.push_back(mapaOrganizmow[x][y].get());
	logger.push_back(log);
}

#endif /* SWIAT_H_ */
