#include <iostream>
#include "elementCounter.hpp"

int main()
{
  using namespace rebdev;

  int firstElement = 0, secondElement = 0;
  std::cin >> firstElement;

  if (!std::cin)
  {
    std::cerr << "Input error!\n";
    return 1;
  }
  else if (firstElement == 0)
  {
    std::cout << "0\n";
    return 0;
  }
  
  std::cin >> secondElement;
  if (!std::cin)
  {
    std::cerr << "Input error!\n";
    return 1;
  }
  
  element_counter objectOfElementCounter(firstElement, secondElement);

  while (secondElement != 0)
  {
    std::cin >> secondElement;

    if (!std::cin)
    {
      std::cerr << "Input error!\n";
      return 1;
    }
    else if (secondElement != 0)
    {
      try
      {
        objectOfElementCounter(secondElement);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << '\n';
        return 2;
      }
    }
  }

  std::cout << objectOfElementCounter() << '\n';
  return 0;
}
