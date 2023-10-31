#include <iostream>
#include "counterreversal.h"

int main()
{
  using namespace gladyshev;
  long long int number = 1;
  CounterReversal result;
  while (number != 0)
  {
    std::cin >> number;
    if (!std::cin)
    {
      return 1;
    }
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

