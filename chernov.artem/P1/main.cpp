#include "piftriples_counter.hpp"
#include "almost_max.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  int number = 0;
  using namespace chernov;
  PifTriplesCounter findPifTriples;
  AlmostMax findSubMax;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    try
    {
      findSubMax(number);
      findPifTriples(number);
    }
    catch (const std::exception & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      return 2;
    }
  }
  while (number != 0);
  std::cout << findSubMax() << "\n";
  std::cout << findPifTriples() << "\n";
  return 0;
}
