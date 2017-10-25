#include <iostream>
#include "WartoscLiczbowa.h"
#include "Liczba.h"
#include "Complex.h"
#include <memory>
#include <vector>

int main()
{
  std::cout << "Zad 3, pierwszy pod punkty \n";

  Liczba l1(2.5);
  Liczba l2(3.7564);
  std::cout << l1;
  std::cout << l2;

  WartoscLiczbowa *l3 = new Liczba(-4.75);
  l3->wypisz(std::cout);
  std::cout << "Modul z l3: " << l3->modul() << "\n\n";

  l1 = l1 + (-5.241);
  std::cout << "l1 + (-5.241) = " << l1 << "\n";
  std::cout << "Warosc bezwlgedna z l1: " << l1.modul() << "\n\n";

  std::cout << "Przyklad z przeciazaniem funkcji \n";
  l1.func(5);
  l1.func("test");
  std::cout << "\n\n";

  Complex c1(2, 1);
  c1.wypisz(std::cout);
  c1 = c1 + (5);
  c1.wypisz(std::cout);
  std::cout << "Wartosc bezwgledna liczby complex c1" << c1.modul() << "\n";

  WartoscLiczbowa *c2 = new Complex(14.5, 22.4);
  std::cout << "Complex przez wskaznik: \n";
  c2->wypisz(std::cout);

  std::cout << "\n\n";

  std::cout << "Drugi pod punkt \n";

  std::vector<std::unique_ptr<WartoscLiczbowa>> arr; // smart pointer eliminuje new i delete

  arr.push_back(std::make_unique<Liczba>(11.35));
  arr.push_back(std::make_unique<Liczba>(-7.4657));
  arr.push_back(std::make_unique<Complex>(-22.8, 14.4));
  arr.push_back(std::make_unique<Complex>(-4.2, 9.8));

  std::cout << "Wypisuje wartosci: \n";

  for(unsigned i=0;i<arr.size();i++) {
	  arr[i]->wypisz(std::cout);
  }

  std::cout << "Wypisuje wartosci bezwgledne: \n";

  for(unsigned i=0;i<arr.size();i++) {
	  std::cout << arr[i]->modul() << "\n";
  }

  return 0;
}
