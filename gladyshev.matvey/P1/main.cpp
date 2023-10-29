#include <iostream>
#include "counterresult.h"

int main()
{
  using namespace gladyshev;
  long long int number = 1;
  unsigned long long counter = 0;
  Counterreversal result;
  while (number != 0)
  {
    std::cin >> number;
    if (!std::cin)
    {
      return 1;
    }
    if (counter == 0 && number == 0)
    {
      std::cout << "zero sequence\n";
    }
    ++counter;
    try
    {
      result(number);
    }
    catch (const std::exception & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      return 2;
    }
  }
  std::cout << result() << "\n";
}

