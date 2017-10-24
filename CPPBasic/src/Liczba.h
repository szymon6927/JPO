#ifndef Liczba_h
#define Liczba_h

#include <iostream>
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
private:
	double re; //czesc rzeczywista
};

#endif
