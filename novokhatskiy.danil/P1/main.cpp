#include <iostream>
#include <stdexcept>
#include "Sequence_counterMax.hpp"

int main()
{
  using namespace novokhatskiy;
  SequenceCounterMax counter;
  int num = 0;
  std::cin >> num;
  if (!std::cin)
  {
    std::cerr << "It is not a number\n";
    return 1;
  }
  while (num != 0)
  {
    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "It is not a number\n";
      return 1;
    }
    else if (num != 0)
    {
      try
      {
        counter(num);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }

    }
  }
  std::cout << counter() << "\n";
  return 0;
}

