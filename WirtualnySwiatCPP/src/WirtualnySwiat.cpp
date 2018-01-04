//============================================================================
// Name        : WirtualnySwiat.cpp
// Author      : Szymon Miks
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <assert.h>
//swiat
#include "Organizm.h"
#include "Swiat.h"
//rosliny
#include "rosliny/Ciern.h"
#include "rosliny/Trawa.h"
#include "rosliny/Guarana.h"
////zwierzeta
#include "zwierzeta/Wilk.h"
#include "zwierzeta/Owca.h"
#include "zwierzeta/Antylopa.h"
#include "zwierzeta/Leniwiec.h"
#include "zwierzeta/Hipopotam.h"

using namespace swiat;

void inputParser(Swiat& zaWarudo, int ilosc, char** args);

int main(int argc, char** argv) {

	srand(time(0)/*trzeba dac dobry seed*/);

	Swiat zaWarudo;

	inputParser(zaWarudo, argc, argv);

	//petelka swiata
	zaWarudo.rysujSwiat();

	std::string control;
	while (true/*(control = std::cin.get()) != 27*/) {
		std::cout << "Wpisz polecenie: ";
		std::cin >> control;
		if (control == "save") {
			std::cout << "Podaj nazwe pliku: ";
			std::string filename;
			std::cin >> filename;
			std::ofstream plik(filename);
			try {
				if (plik.is_open()) {
					plik << zaWarudo.zachowajSwiat();
				} else {
					throw 45;
				}
			} catch (int e) {
				std::cout << "B³¹d " << e;
				std::cout << " - nieprawid³owy plik" << std::endl;
				std::cout << "U¿ywam domyœlnego" << std::endl;
				std::ofstream plik("save.txt");
				plik << zaWarudo.zachowajSwiat();
			}
			plik.close();
		} else if (control == "exit") {
			break;
		}
		zaWarudo.wykonajTure();
		zaWarudo.rysujSwiat();
	}

	return 0;
}

void inputParser(Swiat & zaWarudo, int argc, char ** argv) {

	 std::cout<<"input parser\n";

	std::vector<std::string> organizmy;

	for (int i = 1; i < argc; i++) {

		if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {

			std::string linia;
			std::ifstream plik(argv[i + 1]);
			if (plik.is_open()) {
				while (plik >> linia) {
					organizmy.push_back(linia);
				}
				plik.close();
				break;
			}
		} else if (strcmp(argv[i], "-f") == 0 && i == argc - 1) {
			std::cout << "Brak podanego pliku" << std::endl;
			break;
		} else {
			std::string str(argv[i]);
			organizmy.push_back(str);
		}

	}

	if (organizmy.size() == 0) {
		std::cout << "Brak organizmów" << std::endl;
		exit(EXIT_FAILURE);
	}

	const char* znak;
	for (unsigned int i = 0; i < organizmy.size(); i++) {

		znak = organizmy[i].c_str();
		char zwierzak = 0;
		int x = -1;
		int y = -1;
		int w = 0;

		while (*znak != 0) {
			switch (*znak) {
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
				x = atoi(znak + 1);
				break;
			case 'y':
				y = atoi(znak + 1);
				break;
			case 'w':
				w = atoi(znak + 1);
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
					std::cout << "g - guarana; c - cierñ; t - trawa"
							<< std::endl;
					std::cout << "x - polozenie w osi X; y - polozenie w osi Y"
							<< std::endl;
					std::cout << "w - wiek organizmu" << std::endl;
					std::cout << "Przykladowa konstrukcja: Px2y0w5s0 Wx13y7"
							<< std::endl;
					exit(EXIT_FAILURE);
				}
				;
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
		if (zaWarudo.mapaOrganizmow[x][y] == nullptr) {
			switch (zwierzak) {
			case 'W':
				zaWarudo.mapaOrganizmow[x][y] = new zwierze::Wilk(x, y);
				break;
			case 'L':
				zaWarudo.mapaOrganizmow[x][y] = new zwierze::Leniwiec(x, y);
				break;
			case 'A':
				zaWarudo.mapaOrganizmow[x][y] = new zwierze::Antylopa(x, y);
				break;
			case 'O':
				zaWarudo.mapaOrganizmow[x][y] = new zwierze::Owca(x, y);
				break;
			case 'H':
				zaWarudo.mapaOrganizmow[x][y] = new zwierze::Hipopotam(x, y);
				break;
			case 'c':
				zaWarudo.mapaOrganizmow[x][y] = new roslina::Ciern(x, y);
				break;
			case 'g':
				zaWarudo.mapaOrganizmow[x][y] = new roslina::Guarana(x, y);
				break;
			case 't':
				zaWarudo.mapaOrganizmow[x][y] = new roslina::Trawa(x, y);
				break;
			}
			//podstawowe parametry przy wczytywaniu
			zaWarudo.organizmy.push_back(zaWarudo.mapaOrganizmow[x][y]);
			zaWarudo.mapaOrganizmow[x][y]->setSwiat(zaWarudo);
			zaWarudo.mapaOrganizmow[x][y]->setWiek(w);
		} else {
			std::cout << "Pole zajête" << std::endl;
		}
	}
}
