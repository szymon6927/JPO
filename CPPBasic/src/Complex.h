#ifndef Complex_h
#define Complex_h

#include <ostream>
#include "WartoscLiczbowa.h"

class Complex : public WartoscLiczbowa
{
public:
	~Complex(void);
	Complex(double re=0,double im=0) ;
	Complex operator+(const Complex& right) {
		return Complex(this->re + right.re, this->im + right.im);
	}
	friend std::ostream& operator<<(std::ostream &out, Complex &l);
	double modul();
	void wypisz(std::ostream &out) {
		out << *this;
	}
private:
	double re;
	double im; //czesc urojona
};

#endif
