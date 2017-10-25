#include "Complex.h"
#include <iostream>
#include <cmath>

Complex::Complex(double re, double im) : re(re), im(im)
{
	std::cout << "Konstruktor liczby complex Re: " << this->re << ", Im: " << this->im << "\n";
}

Complex::~Complex(void) {
//	std::cout << "Likwiduje obiekt klasy Complex zawartosc to: " << this->re << " " << this->im << "\n";
}

std::ostream& operator<<(std::ostream& out, Complex& c) {
	return out << "Liczba urojona: " << c.re << " + " << c.im << "i\n";
}

double Complex::modul() {
	return std::hypot(this->re, this->im);
}
