#include <iostream>
#include "aftmax.hpp"
#include "samemin.hpp"


int main()
{
  using namespace vojuck;
  CounterAftMax aftMaxCounter;
  CounterSameMin sameMinCounter;
  int number = 0;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    else if (number != 0)
    {
      try
      {
        aftMaxCounter(number);
        sameMinCounter(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (number != 0);
  std::cout << "AftMax counter: " << aftMaxCounter() << " SameMin counter: " << sameMinCounter() << "\n";
}
