#include "loc_max.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  long long number = 0;

  using namespace shabalin;

  LocMax counter;

  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "is not sequence" << "\n";
      return 1;
    }
    if (number != 0)
    {
      try
      {
        counter(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (number != 0);
  std::cout << counter() << "\n";
}
