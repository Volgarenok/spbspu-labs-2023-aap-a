#include <iostream>
#include <stdexcept>
#include "sequence_counter.hpp"

int main()
{
  int number = 0;
  using namespace sakovskaia;
  SequenceSignsCounter counter;
  size_t size = 0;
  int lastNumber = 0;
  do
  {
    lastNumber = number;
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    else if (number != 0 && lastNumber != 0)
    {
      try
      {
        ++size;
        counter(size, number);
        counter(lastNumber, number);
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
