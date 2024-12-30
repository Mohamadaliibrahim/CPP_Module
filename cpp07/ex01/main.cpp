#include <iostream>
#include "iter.hpp"

void printInt(int &x)
{
    std::cout << x << " ";
}

void printDouble(double &x)
{
    std::cout << x << " ";
}

void printString(std::string &x)
{
    std::cout << x << " ";
}

void increment(int &x)
{
    x += 1;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}