#include <iostream>
#include "sequence.hpp"

int main()
{
  using namespace marishin;
  QuantitySumOfThePreviousTwo seq;
  long long int num;
  do
  {
    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    else if (num != 0)
    {
      try
      {
        seq(num);
      }
      catch (const std::exception& e)
      {
        std::cerr << "ERROR: " << e.what() << "\n";
        return 2;
      }
    }
  } while (num != 0);
  try
  {
    std::cout << seq() << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << "ERROR: " << e.what() << "\n";
    return 2;
  }
}
