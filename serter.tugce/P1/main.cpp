#include <iostream>
#include <stdexcept>
#include "countOfSignsChangesInSeq.hpp"

int main()
{
  int number = 0;
  using namespace serter;
  CountOfSignsChangesInSeq counter;
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
        counter(number);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (number != 0);
  std::cout << counter() << "\n";
}

