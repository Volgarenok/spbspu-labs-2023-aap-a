#include <iostream>
#include "sequence_counter.hpp"
#include "count_even_nums.hpp"

int main()
{
  long long int number = 0;
  size_t maxChetCount = 0;
  size_t currentChetCount = 0;
  using namespace nikitov;
  SequenceCounter counter;

  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Error: This is not a sequence\n";
      return 1;
    }
    else if (number != 0)
    {
      try
      {
        counter(number);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Error: " << e.what() << '\n';
        return 2;
      }
      countEvenNums(number, maxChetCount, currentChetCount);
    }
  }
  while (number != 0);

  std::cout << maxChetCount << '\n';
  try
  {
    std::cout << counter() << '\n';
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 2;
  }
  return 0;
}
