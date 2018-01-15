#include <fstream>
#include <ctime>
#include <cstring>
#include <cassert>
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

void inputParser(Swiat& swiat, int ilosc, char** args);

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
					throw std::runtime_error("nie moge otworzyc tego pliku");
				}
			} catch (std::exception const& e) {
				std::cout << "Blad " << e.what();
				std::cout << " - nieprawidlowy plik" << std::endl;
				std::cout << "Uzywam domyslnego (save.txt)" << std::endl;
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

void inputParser(Swiat& swiat, int argc, char ** argv) {

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
		std::cout << "Brak organizmow" << std::endl;
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
			case 'w': //wiek zwierzecia
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
					std::cout << "g - guarana; c - ciern; t - trawa"
							<< std::endl;
					std::cout << "x - polozenie w osi X; y - polozenie w osi Y"
							<< std::endl;
					std::cout << "w - wiek organizmu" << std::endl;
					std::cout << "Przykladowa konstrukcja: Hx2y0w5 Wx13y7"
							<< std::endl;
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
		if (swiat.mapaOrganizmow[x][y] == nullptr) {
			switch (zwierzak) {
			case 'W':
				swiat.mapaOrganizmow[x][y] = new zwierze::Wilk(swiat ,x, y);
				break;
			case 'L':
				swiat.mapaOrganizmow[x][y] = new zwierze::Leniwiec(swiat, x, y);
				break;
			case 'A':
				swiat.mapaOrganizmow[x][y] = new zwierze::Antylopa(swiat, x, y);
				break;
			case 'O':
				swiat.mapaOrganizmow[x][y] = new zwierze::Owca(swiat, x, y);
				break;
			case 'H':
				swiat.mapaOrganizmow[x][y] = new zwierze::Hipopotam(swiat, x, y);
				break;
			case 'c':
				swiat.mapaOrganizmow[x][y] = new roslina::Ciern(swiat, x, y);
				break;
			case 'g':
				swiat.mapaOrganizmow[x][y] = new roslina::Guarana(swiat, x, y);
				break;
			case 't':
				swiat.mapaOrganizmow[x][y] = new roslina::Trawa(swiat, x, y);
				break;
			}
			//podstawowe parametry przy wczytywaniu
			swiat.organizmy.push_back(swiat.mapaOrganizmow[x][y]);
			swiat.mapaOrganizmow[x][y]->setWiek(w);
		} else {
			std::cout << "Pole zajete" << std::endl;
		}
	}
}
