/*
 * Swiat.cpp
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */
#include "Swiat.h"

Swiat::Swiat() {

	mapaOrganizmow = new organizm::Organizm**[20];
	for (int i = 0; i < 20; i++) {

		mapaOrganizmow[i] = new organizm::Organizm*[20];
		for (int j = 0; j < 20; j++) {
			mapaOrganizmow[i][j] = nullptr;
		}
	}

	mapa = new char*[20];
	for (int i = 0; i < 20; i++) {
		mapa[i] = new char[20];

		for (int j = 0; j < 20; j++) {
			mapa[i][j] = ' ';
		}
	}

}

bool Swiat::sortowanie(organizm::Organizm* i, organizm::Organizm* j) {
	int tmp_i = i->getInicjatywa();
	int tmp_j = j->getInicjatywa();

	if (tmp_i == tmp_j) {
		return (i->getWiek() > j->getWiek());
	}
	return (tmp_i > tmp_j);
}

bool Swiat::sortowanieZywych(organizm::Organizm* i, organizm::Organizm* j) {
	return (i->czyZywy() > j->czyZywy());
}

void Swiat::rysujSwiat() {

	std::system("clear");

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			mapa[i][j] = ' ';
		}
	}

	int size = organizmy.size();

	for (int i = 0; i < size; i++) {
		organizmy[i]->rysowanie();
	}

	for (unsigned i = 0; i < 20; i++) {
		for (unsigned j = 0; j < 20; j++) {
			std::cout << mapa[i][j];
		}
		if (i < logger.size()) {
			std::cout << "\t" << logger[i];
		}
		std::cout << std::endl;
	}
	logger.clear();
	std::cout << std::endl << std::endl;
	std::cout << "Szymon Miks 166249" << std::endl;
	std::cout << "save - zapisuje swiat do wskazanego pliku" << std::endl;
	std::cout << "exit - opuszcza program" << std::endl;
	std::cout << "Kazdy inny tekst bedzie kontynuowac program" << std::endl;
}

void Swiat::wykonajTure() {

	int ilosc = organizmy.size();

	for (int i = 0; i < ilosc; i++) {
		organizmy[i]->setWiek();
	}

	for (int i = 0; i < ilosc; i++) {

		if (organizmy[i]->czyZywy()) {
			organizmy[i]->akcja();
		}
	}

	std::sort(organizmy.begin(), organizmy.end(), sortowanieZywych);

	for (int i = ilosc - 1; i >= 0; i--) {
		if (!organizmy[i]->czyZywy()) {
			delete organizmy[i];
			organizmy.erase(organizmy.begin() + i);
		} else {
			break;
		}
	}

	std::sort(organizmy.begin(), organizmy.end(), sortowanie);
}

std::string Swiat::zachowajSwiat() {

	std::string str;
	for (unsigned i = 0; i < organizmy.size(); i++) {
		//dla kazdego elementy wektora wypisz pozycje,wiek,rodzaj i stun:
		// W12x15w5s1
		//g++ -std=c++0x zeby dzialalo
		//http://www.linuxquestions.org/questions/programming-9/error-to_string-was-not-declared-in-this-scope-4175513090/
		str.push_back(organizmy[i]->getSymbol());
		str.append("x");
		str.append(std::to_string(organizmy[i]->getX()));
		str.append("y");
		str.append(std::to_string(organizmy[i]->getY()));
		str.append("w");
		str.append(std::to_string(organizmy[i]->getWiek()));
		str.append(" ");

	}
	str.pop_back();
	str.append("\n");

	return str;
}

void Swiat::utworzSwiat() {
	//nie zapomnij ustawic adresu mapy do rysowania!!!
	//asserty, zeby pozycje nie byly wieksze niz wyymiar mapy, bo segvfault
	std::sort(organizmy.begin(), organizmy.end(), sortowanie);
}

Swiat::~Swiat() {

	int size = organizmy.size();

	for (int i = 0; i < size; i++) {
		delete organizmy[i];
	}

	for (int i = 0; i < 20; i++) {
		delete mapa[i];
	}
	delete[] mapa;

	organizmy.clear();
	std::cout << "Destrukcja mapy" << std::endl;

	for (unsigned i = 0; i < 20; i++) {
		for (unsigned j = 0; j < 20; j++) {
			mapaOrganizmow[i][j] = nullptr;
		}
	}

	for (int i = 0; i < 20; i++) {
		delete mapaOrganizmow[i];
	}
	delete[] mapaOrganizmow;

	std::cout << "Zabijamy organizmy" << std::endl;

	for (unsigned i = 0; i < logger.size(); i++) {
		std::cout << logger[i] << std::endl;
	}

	logger.clear();
}

