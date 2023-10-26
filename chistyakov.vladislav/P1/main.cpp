#include <iostream>
#include <stdexcept>
#include "SequenceNumOfMax.hpp"

int main()
{
  int nowNum = 0;
  std::cin >> nowNum;

  if (!std::cin)
  {
    std::cerr << "Bad input, try again\n";
    return 1;
  }
  else if (nowNum == 0)
  {
    std::cout << "There are no numbers in the sequence, the number of maximum numbers: 0\n"; 
    return 0;
  }
  SequenceNumOfMax counter;
  counter.start_max(nowNum);

  do
  {
    std::cin >> nowNum;
    if (!std::cin)
    {
      std::cerr << "Bad input, try again\n";
      return 1;
    }
    else if (nowNum != 0)
    {
      try
      {
        counter.count(nowNum);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (nowNum != 0);
  std::cout << counter.get_result() << "\n";
  return 0;
}
