#include <iostream>
#include "sign_change_counter.hpp"
#include "sum_dup_counter.hpp"

int main()
{
  using namespace ishmuratov;
  SignChangeCounter changeCount;
  SumDupCounter sumCount;
  long long int num = 1;
  while (num != 0)
  {
    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "Input error, it's not a sequence\n";
      return 1;
    }
    try
    {
      if (num != 0)
      {
        changeCount(num);
        sumCount(num);
      }
    }
    catch (const std::exception& e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      return 2;
    }
  }
  std::cout << changeCount() << "\n";
  try
  {
    std::cout << sumCount() << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
}
