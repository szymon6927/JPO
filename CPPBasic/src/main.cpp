#include <iostream>
#include "Liczba.h"

int main()
{
  std::cout << "Hello World!" << std::endl;
  Liczba l1(2.5);
  Liczba l2(3.7564);
  std::cout << l2;
  l1.modul();
  std::cout << l1;
  return 0;
}
