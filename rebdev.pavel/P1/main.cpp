#include <iostream>
#include "elementCounter.hpp"

int main()
{
  using namespace rebdev;

  int number = 0;

  ElementCounter objectOfElementCounter;

  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Input error!\n";
      return 1;
    }
    try
    {
      objectOfElementCounter(number);
    }
    catch (const std::exception & e)
    {
      std::cerr << "Error: " << e.what() << '\n';
      return 2;
    }
  }
  while (number != 0);
  try
  {
    size_t a = objectOfElementCounter();
    std::cout << a << '\n';
    return 0;
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 2;
  }
}
