#include <iostream>
#include "Liczba.h"
#include "Complex.h"
#include <memory>
#include <vector>

int main()
{
  Liczba l1(2.5);
  Liczba l2(3.7564);
  std::cout << l1;
  std::cout << l2;
  l1 = l1 + (-5.241);
  std::cout << "l1 + (-5.241) = " << l1 << "\n";
  std::cout << "Warosc bezwlgedna z l1: " << l1.modul() << "\n";
  Complex c1(2, 1);
  c1.wypisz(std::cout);
  c1 = c1 + (5,5);
  c1.wypisz(std::cout);
  std::cout << c1.modul();

  std::vector<std::unique_ptr<WartoscLiczbowa>> v; // smart pointer to avoid new/delete expressions, works the same as std::vector<NumericValue*>

  v.push_back(std::make_unique<Liczba>(17.4));
	v.push_back(std::make_unique<Liczba>(-17.4));
	v.push_back(std::make_unique<Complex>(-10.8, 5.9));
	v.push_back(std::make_unique<Complex>(-5.9, 10.8));

	std::cout << "Values:\n";

	for (const auto& elem : v)
		elem->wypisz(std::cout);

	std::cout << "Absolute values:\n";

	for (const auto& elem : v)
		std::cout << elem->modul() << '\n';


  return 0;
}
