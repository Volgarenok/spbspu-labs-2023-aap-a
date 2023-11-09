#include <iostream>
#include "counterofnums.hpp"

int main()
{
  int currentNum = 1;

  using namespace arakelyan;
  CounterOfNumsThatDevideByThePrev counter;

  while (currentNum != 0)
  {
    std::cin >> currentNum;
    if (!std::cin)
    {
      std::cerr << "Enter num!\n";
      return 1;
    }
    try
    {
      counter(currentNum);
    }
    catch (const std::exception & e)
    {
      std::cout << "Error: " << e.what() << "\n";
      return 2;
    }
  }


  try {
    std::cout << counter() << "\n";
  }
  catch (const std::exception & e)
  {
    std::cout << "Error: " << e.what() << "\n";
    return 2;
  }
}
