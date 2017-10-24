#include "Liczba.h"
#include <iostream>
#include <cmath>
using namespace std;

Liczba::Liczba(double re) {
	cout<<"Konstruktor Liczba = "<<re<<"\n";
	this->re = re;
}

Liczba::~Liczba(void) {
	cout << "Likwiduje obiekt klasy Liczba \n";
}

double Liczba::modul() {
	return fabs(this->re);
}

std::ostream & operator<<(std::ostream &out, Liczba &l) {
	out<<"Liczba rzeczywista: " << l.re<<"\n";
	return out;
}
