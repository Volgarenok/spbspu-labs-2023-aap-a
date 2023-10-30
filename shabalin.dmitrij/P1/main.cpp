#include <iostream>
#include "locmax.hpp"
#include <stdexcept>


int main()
{
  int behindNum, curNum,  nextNum = 1;
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
  else if (curNum == 0)
  {
    std::cout << "Can not be calculated";
    return 0;
  }

  using namespace shabalin;

  LocMax counter(behindNum,curNum);
  
  
  while (nextNum != 0)
  {
    std::cin >> nextNum;
    if (!std::cin)
    {
      std::cerr << "is not sequence\n";
      return 1;
    }
    try 
    {
      counter(nextNum);
    }
    catch(const std::exception & e)
    {
      std::cerr << "Error: " << e.what()<< "\n";
      return 2;
    }
  }
  std::cout << counter() << "\n";
}