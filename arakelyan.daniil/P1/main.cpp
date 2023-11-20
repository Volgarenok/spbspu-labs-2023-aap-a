#include <iostream>
#include "counterofnums.hpp"

int main()
{
  int currentNum = 0;

  using namespace arakelyan;
  CounterOfNumsThatDevideByThePrev counter;

  do
  {
    std::cin >> currentNum;
    if (!std::cin)
    {
      std::cerr << "It's not a sequence!\n";
      return 1;
    }
    try
    {
      if (currentNum != 0)
      {
        counter.counterOfSequence(currentNum);
      }
    }
    catch (const std::exception & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      return 2;
    }
  }
  while (currentNum != 0);

  size_t answ = 0;
  try
  {
    answ = counter.getCount();
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  std::cout << "Answer: " << answ << "\n";
}
