#include "counterreversal.h"

#include <iostream>

int main()
{
  using namespace gladyshev;
  long long int number_ = 1;
  CounterReversal result;
  while (number_ != 0)
  {
    std::cin >> number_;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    try
    {
      result(number_);
    }
    catch (const std::exception & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      return 2;
    }
  }
  std::cout << result() << "\n";
}
