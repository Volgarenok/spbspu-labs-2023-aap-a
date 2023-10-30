#include <iostream>
#include "counterofnums.hpp"

int main()
{
  int currentNum = 0;
  int pastNum = 0;

  using namespace arakelyan;
  CounterOfNums count;

  std::cin >> currentNum;
  if (!std::cin)
  {
    std::cerr << "Enter num\n";
    return 1;
  }
  else if (currentNum == 0)
  {
    std::cerr << "Zero sequence\n";
    return 2;
  }

  try
  {
    while (currentNum != 0)
    {
      pastNum = currentNum;
      std::cin >> currentNum;
      if (!std::cin)
      {
        std::cerr << "Enter num\n";
        return 1;
      }
      count.counter(currentNum, pastNum);
    }
  }
  catch (const std::exception & e)
  {
    std::cout << "Error: " << e.what() << "\n";
    return 2;
  }
  std::cout << "Answer: " << count.get_count() << "\n";
  return 0;
}
