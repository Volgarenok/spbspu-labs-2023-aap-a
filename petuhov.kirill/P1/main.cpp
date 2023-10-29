#include <iostream>
#include <stdexcept>
#include "sequence_even_counter.hpp"

int main()
{
  int num = 0;
  using namespace petuhov;
  SequenceEvenCounter counter;

  while (true)
  {
    std::cin >> num;

    if (!std::cin)
    {
      std::cerr << "Input is not a valid number!" << std::endl;
      return 1;
    }
    if (num == 0)
    {
      break;
    }
    else
    {
      try
      {
        counter(num);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << std::endl;
        return 2;
      }
    }
  }

  std::cout << counter() << std::endl;
}
