#include <iostream>
#include <stdexcept>
#include "sequence_even_counter.hpp"

int main()
{
  int num = 0;
  using namespace petuhov;
  SequenceEvenCounter counter;

  do
  {
    std::cin >> num;

    if (!std::cin)
    {
      std::cerr << "Input is not a valid number!\n";
      return 1;
    }
    else
    {
      if (num != 0)
      {
        try
        {
          counter(num);
        }
        catch (const std::exception & e)
        {
          std::cerr << "Error: " << e.what() << "\n";
          return 2;
        }
      }
    }
  }
  while (num != 0);

  std::cout << counter() << "\n";
}
