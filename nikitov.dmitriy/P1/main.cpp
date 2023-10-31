#include <iostream>
#include "sequence_counter.hpp"
#include "is_max.hpp"
#include "chet_counter.hpp"

int main()
{
  int number = 0;
  int actualMax = 0;
  int preMax = 0;
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
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << '\n';
        return 2;
      }
      isMax(number, actualMax, preMax);
      chetCounter(number, maxChetCount, currentChetCount);
    }
  }
  while (number != 0);

  std::cout << maxChetCount << '\n';
  if (counter() == 0 || counter() == 1)
  {
    std::cerr << "Error: This sequence is too short for SUB-MAX\n";
    return 2;
  }
  std::cout << preMax << '\n';
  return 0;
}
