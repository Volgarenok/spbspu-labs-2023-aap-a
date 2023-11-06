#include "loc_max.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  signed long long firstNumber = 1, secondNumber = 1,  thirdNumber = 1, Number = 1;
  
  std::cin >> firstNumber;

  if (!std::cin)
  {
    std::cerr << "Is not sequence" << "\n";
    return 1;
  }
  else if (firstNumber == 0)
  {
    std::cerr << "Must be no zero sequence" << "\n";
    return 2;
  }

  std::cin >> secondNumber;

  if (!std::cin)
  {
    std::cerr << "Is not sequence" << "\n";
    return 1;
  }
  else if (secondNumber == 0)
  {
    std::cerr << "Can not be calculated" << "\n";
    return 0;
  }

  std::cin >> thirdNumber;
  
  if (!std::cin)
  {
    std::cerr << "Is not sequence" << "\n";
    return 1;
  }
  else if (thirdNumber == 0)
  {
    std::cerr << "Can not be calculated" << "\n";
    return 0;
  }
  
  using namespace shabalin;
  
  LocMax counter(firstNumber, secondNumber, thirdNumber);

  do
  {
    std::cin >> Number;
    if (!std::cin)
    {
      std::cerr << "is not sequence" << "\n";
      return 1;
    }
    if (Number != 0)
    {
      try
      {
        counter(Number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (Number != 0);
  std::cout << counter() << "\n";
}
