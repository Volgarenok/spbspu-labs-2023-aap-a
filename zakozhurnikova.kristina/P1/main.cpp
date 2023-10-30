#include <iostream>
#include <stdexcept>
#include "sequence_counter.hpp"

int main ()
{
  int number = 0;
  using namespace zakozhurnikova;
  SequenceCounter counter;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Is not sequence\n";
      return 1;
    }
    else if (number != 0)
    {
      try
      {
        counter.count(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (number != 0);
  std::cout << counter.get_result() << "\n";
}
