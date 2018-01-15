#include <fstream>
#include <ctime>
#include <cstring>
#include <cassert>
#include "Swiat.h"

int main(int argc, char** argv) {

	srand(time(0)/*trzeba dac dobry seed*/);

	Swiat swiat;

	swiat.inputParser(argc, argv);

	//petelka swiata
	swiat.rysujSwiat();

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
					plik << swiat.zachowajSwiat();
				} else {
					throw std::runtime_error("nie moge otworzyc tego pliku");
				}
			} catch (std::exception const& e) {
				std::cout << "Blad " << e.what();
				std::cout << " - nieprawidlowy plik" << std::endl;
				std::cout << "Uzywam domyslnego (save.txt)" << std::endl;
				std::ofstream plik("save.txt");
				plik << swiat.zachowajSwiat();
			}
			plik.close();
		} else if (control == "exit") {
			break;
		}
		swiat.wykonajTure();
		swiat.rysujSwiat();
	}

	return 0;
}
