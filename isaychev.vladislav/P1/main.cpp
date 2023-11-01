#include <iostream>
#include <limits>
#include <stdexcept>
#include "even_counter.hpp"

int main()
{
  isaychev::EvenCounter counter1;
  int c_number = 0;
  std::cin >> c_number;
  if (!std::cin)
  {
    std::cerr << "not a number was inputed\n";
    return 1;
  }
  while (c_number != 0)
  {
    try
    {
      counter1(c_number);
    }
    catch (const std::exception & e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
    std::cin >> c_number;
    if (!std::cin)
    {
      std::cerr << "not a number was inputed\n";
      return 1;
    }
  }
  std::cout << counter1() << "\n";
}
