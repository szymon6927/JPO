#include "Liczba.h"
#include <iostream>
#include <cmath>
using namespace std;

Liczba::Liczba(double re) {
	cout<<"Konstruktor Liczba = "<<re<<"\n";
	this->re = re;
}

Liczba::~Liczba(void) {
	cout << "Likwiduje obiekt klasy Liczba zawartosc to: " << this->re << "\n";
}

double Liczba::modul() {
	return fabs(this->re);
}

std::ostream& operator<<(std::ostream& out, Liczba& l) {
	return out<<"Liczba rzeczywista: " << l.re << "\n";
}
