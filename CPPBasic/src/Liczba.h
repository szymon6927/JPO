#ifndef Liczba_h
#define Liczba_h

#include <iostream>
#include <string>
#include "WartoscLiczbowa.h"

class Liczba : public WartoscLiczbowa
{
public:
	Liczba(double re);
	~Liczba(void);

	Liczba operator+(const Liczba& right) {
		return Liczba(this->re + right.re);
	}
	double modul();
	friend std::ostream& operator<<(std::ostream &out, Liczba &l);

	void wypisz(std::ostream &out) {
		out << *this;
	}

//	void test() override {}; // przyk³ad pokazuj¹cy, ¿e je¿eli w klasie bazowej nie ma funkcji test to kompilator da b³¹d
	void func(int) {
		std::cout << "int \n";
	}

	void func(std::string) {
		std::cout << "string \n";
	}
private:
	double re; //czesc rzeczywista
};

#endif
