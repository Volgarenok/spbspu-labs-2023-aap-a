#include <iostream>
#include <stdexcept>
#include "counter_of_numbers_equal_to_the_maximum.hpp"

int main()
{
  int number = 0;
  using namespace belokurskaya;
  CounterOfNumbersEqualToTheMaximum counter;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << " Is not a sequence\n";
      return 1;
    }
    else if (number != 0)
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
