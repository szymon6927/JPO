/*
 * Swiat.cpp

 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */
#include <fstream>
#include <cassert>
#include <cstring>

#include "Swiat.h"
#include "Organizm.h"
//rosliny
#include "rosliny/Ciern.h"
#include "rosliny/Trawa.h"
#include "rosliny/Guarana.h"
//zwierzeta
#include "zwierzeta/Wilk.h"
#include "zwierzeta/Owca.h"
#include "zwierzeta/Antylopa.h"
#include "zwierzeta/Leniwiec.h"
#include "zwierzeta/Hipopotam.h"

Swiat::Swiat() {
	logger.push_back("\tUtworzenie Swiata");
}

bool Swiat::sortowanie(Organizm* i, Organizm* j) {
	int tmp_i = i->getInicjatywa();
	int tmp_j = j->getInicjatywa();

	if (tmp_i == tmp_j) {
		return (i->getWiek() > j->getWiek());
	}
	return (tmp_i > tmp_j);
}

void Swiat::rysujSwiat() {

	std::system("clear");

	unsigned logLine = 0;
	for (const auto& row : mapaOrganizmow) {
		for (const auto& organizm : row) {
			if (organizm == nullptr)
				std::cout << ' ';
			else
				std::cout << organizm->getSymbol();
		}
		if (logLine < logger.size()) {
			std::cout << "\t" << logger[logLine];
		}
		++logLine;
		std::cout << '\n';
	}

	logger.clear();
	std::cout << std::endl << std::endl;
	std::cout << "Szymon Miks 166249" << std::endl;
	std::cout << "save - zapisuje swiat do wskazanego pliku" << std::endl;
	std::cout << "exit - opuszcza program" << std::endl;
	std::cout << "Kazdy inny tekst bedzie kontynuowac program" << std::endl;
}

Organizm* Swiat::znajdzOrganizmPoPozycji(int x, int y) {
	return mapaOrganizmow[x][y].get();
}

void Swiat::zamienMiejscami(int x1, int y1, int x2, int y2) noexcept {
	mapaOrganizmow[x1][y1]->setX(x2);
	mapaOrganizmow[x1][y1]->setY(y2);

	if (mapaOrganizmow[x2][y2] != nullptr) {
		mapaOrganizmow[x2][y2]->setX(x1);
		mapaOrganizmow[x2][y2]->setY(y1);
	}
	std::swap(mapaOrganizmow[x1][y1], mapaOrganizmow[x2][y2]);
}

void Swiat::wykonajTure() {

	for (auto& col : mapaOrganizmow) {
		for (auto& organizm : col) {
			if (organizm != nullptr) {
				organizmy.push_back(organizm.get());
			}
		}
	}

	std::sort(organizmy.begin(), organizmy.end(), sortowanie);

	for (auto& organizm : organizmy) {
		organizm->zwiekszWiek();
		if (organizm->czyZywy()) {
			organizm->akcja();
		}
	}

	for (auto& col : mapaOrganizmow) {
		for (auto& organizm : col) {
			if (organizm != nullptr && !organizm->czyZywy()) {
				organizm = nullptr; // zwalniamy pamiec - wolany dtor
			}
		}
	}

	organizmy.clear();
}

std::string Swiat::zachowajSwiat() const {

	std::string str;
	for (unsigned i = 0; i < organizmy.size(); i++) {
		//dla kazdego elementy wektora wypisz pozycje,wiek,rodzaj i stun:
		// W12x15w5s1
		//g++ -std=c++0x zeby dzialalo
		//http://www.linuxquestions.org/questions/programming-9/error-to_string-was-not-declared-in-this-scope-4175513090/
		if (organizmy[i] != nullptr) {
			str.push_back(organizmy[i]->getSymbol());
			str.append("x");
			str.append(std::to_string(organizmy[i]->getX()));
			str.append("y");
			str.append(std::to_string(organizmy[i]->getY()));
			str.append("w");
			str.append(std::to_string(organizmy[i]->getWiek()));
			str.append(" ");
		}

	}
	str.pop_back();
	str.append("\n");

	return str;
}

void Swiat::utworzSwiat() {
	//nie zapomnij ustawic adresu mapy do rysowania!!!
	//asserty, zeby pozycje nie byly wieksze niz wyymiar mapy, bo segvfault
}

Swiat::~Swiat() {
	std::cout << "Destrukcja mapy" << std::endl;
	std::cout << "Zabijamy organizmy" << std::endl;

	for (const auto& log : logger) {
		std::cout << log << std::endl;
	}
}

void Swiat::inputParser(int argc, char** argv) {

	std::vector<std::string> organizmy;

	for (int i = 1; i < argc; i++) {

		if (std::strcmp(argv[i], "-f") == 0 && i + 1 < argc) {

			std::string linia;
			std::ifstream plik(argv[i + 1]);
			if (plik.is_open()) {
				while (plik >> linia) {
					organizmy.push_back(std::move(linia));
				}

				break;
			}
		}
		else if (std::strcmp(argv[i], "-f") == 0 && i == argc - 1) {
			std::cout << "Brak podanego pliku" << std::endl;
			break;
		}
		else {
			std::string str(argv[i]);
			organizmy.push_back(str);
		}

	}

	if (organizmy.empty()) {
		std::cout << "Brak organizmow" << std::endl;
		std::exit(EXIT_FAILURE);
	}
// -----------------------
	const char* znak;
	for (auto& organizm : organizmy) {

		znak = organizm.c_str();
		char zwierzak = 0;
		int x = -1;
		int y = -1;
		int w = 0;

		while (*znak != 0) {
			switch (*znak)
				{
				case 'W':
					zwierzak = 'W';
					break;
				case 'O':
					zwierzak = 'O';
					break;
				case 'L':
					zwierzak = 'L';
					break;
				case 'A':
					zwierzak = 'A';
					break;
				case 'H':
					zwierzak = 'H';
					break;
				case 'c':
					zwierzak = 'c';
					break;
				case 'g':
					zwierzak = 'g';
					break;
				case 't':
					zwierzak = 't';
					break;
				case 'x':
					x = std::atoi(znak + 1);
					break;
				case 'y':
					y = std::atoi(znak + 1);
					break;
				case 'w': //wiek zwierzecia
					w = std::atoi(znak + 1);
					break;
				default:
					try {
						if (!isdigit(*znak)) {
							throw *znak;
						}
					} catch (char e) {
						std::cout << "Niepoprawny znak: " << e << std::endl;
						std::cout << "Dopuszczalne znaki:" << std::endl;
						std::cout << "W - wilk; O - Owca; H - hipopotam" << std::endl;
						std::cout << "A - antylopa; L - Leniwiec" << std::endl;
						std::cout << "g - guarana; c - ciern; t - trawa" << std::endl;
						std::cout << "x - polozenie w osi X; y - polozenie w osi Y" << std::endl;
						std::cout << "w - wiek organizmu" << std::endl;
						std::cout << "Przykladowa konstrukcja: Hx2y0w5 Wx13y7" << std::endl;
						exit(EXIT_FAILURE);
					}
					break;
				}
			znak++;
		}
		assert(x >= 0);
		assert(y >= 0);
		assert(x < 20);
		assert(y < 20);
		assert(zwierzak != 0);
		//sprawdzanie, czy mapaOrganizmow[x][y] == NULL
		if (mapaOrganizmow[x][y] == nullptr) {
			switch (zwierzak)
				{
				case 'W':
					mapaOrganizmow[x][y] = std::make_unique<zwierze::Wilk>(*this, x, y);
					break;
				case 'L':
					mapaOrganizmow[x][y] = std::make_unique<zwierze::Leniwiec>(*this, x, y);
					break;
				case 'A':
					mapaOrganizmow[x][y] = std::make_unique<zwierze::Antylopa>(*this, x, y);
					break;
				case 'O':
					mapaOrganizmow[x][y] = std::make_unique<zwierze::Owca>(*this, x, y);
					break;
				case 'H':
					mapaOrganizmow[x][y] = std::make_unique<zwierze::Hipopotam>(*this, x, y);
					break;
				case 'c':
					mapaOrganizmow[x][y] = std::make_unique<roslina::Ciern>(*this, x, y);
					break;
				case 'g':
					mapaOrganizmow[x][y] = std::make_unique<roslina::Guarana>(*this, x, y);
					break;
				case 't':
					mapaOrganizmow[x][y] = std::make_unique<roslina::Trawa>(*this, x, y);
					break;
				default:
					std::cout << "Zly format!";
				}
			//podstawowe parametry przy wczytywaniu
			mapaOrganizmow[x][y]->setWiek(w);
		}
		else {
			std::cout << "Pole zajete" << std::endl;
		}
	}
}
