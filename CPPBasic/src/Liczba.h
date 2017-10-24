#include <iostream>

#include "WartoscLiczbowa.h"

class Liczba : public WartoscLiczbowa
{
private:
	double re; //czesc rzeczywista
public:
	Liczba operator+(Liczba & right) {
		return Liczba (this->re+right.re);
	}
	double modul();
	Liczba(double re);
	~Liczba(void);
	friend std::ostream & operator<< (std::ostream &out, Liczba &l);

	void wypisz(std::ostream &out) {
		out<<*this;
	}
};
