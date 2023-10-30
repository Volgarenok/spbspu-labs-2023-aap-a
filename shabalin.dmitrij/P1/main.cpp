#include <iostream>
#include "locmax.hpp"
#include <stdexcept>


int main()
{
  int behindNum, curNum,  nextNum = 0;
  std::cin >> behindNum;
  if (!std::cin)
  {
    std::cerr << ("Is not sequence\n");
    return 1;
  }
  else if (behindNum == 0)
  {
    std::cerr << ("must be no zero sequence\n");
    return 2;
  }
  std::cin >> curNum;
  if (!std::cin)
  {
    std::cerr << ("Is not sequence\n");
    return 1;
  }

  using namespace shabalin;

  LocMax counter(behindNum,curNum);

  do 
  {
    std::cin >> nextNum;
    if (nextNum != 0)
    { 
      try {
        counter.count(nextNum);
      }
      catch(const std::exception & e)
      {
        std::cerr << "Error: " << e.what()<< "\n";
        return 2;
      }
    }
    else if (!std::cin)
    {
      std::cerr << "Is not sequence\n";
    }
  }
  while (nextNum != 0);
  std::cout << counter.get_result() << "\n";
}