#include <iostream>
#include <stdexcept>
#include "local_max_counter.hpp"

int main()
{
  long long int firstNumber = 1;
  long long int secondNumber = 1;
  long long int number = 1;

  std::cin >> firstNumber;
  if (!std::cin)
  {
    std::cerr << "Is not a sequence\n";
    return 1;
  }
  else if (firstNumber == 0)
  {
    std::cerr << "A sequence is too short \n";
    return 2;
  }

  std::cin >> secondNumber;
  if (!std::cin)
  {
    std::cerr << "Is not a sequence\n";
    return 1;
  }
  else if (secondNumber == 0)
  {
    std::cout << 0 << '\n';
    return 0;
  }

  using namespace baranov;
  LocalMaxCounter counter(firstNumber, secondNumber);

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
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << '\n';
        return 2;
      }
    }
  }
  while (number != 0);

  std::cout << counter()  << '\n';
}

