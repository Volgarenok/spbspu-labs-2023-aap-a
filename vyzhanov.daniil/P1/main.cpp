#include <stdexcept>
#include <iostream>
#include "composition.hpp"

int main()
{
  vyzhanov::SequenceSpec spec;
  int num = 0;
  do
  {
    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "Is not a sequance\n";
      return 1;
    }
    else if (num != 0)
    {
      try
      {
        spec(num);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (num != 0);
  try
  {
    spec.counter();
    spec.sum1();
    spec.moreLess();
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  std::cout << spec.counter() << "\n";
  std::cout << spec.sum1() << "\n";
  std::cout << spec.moreLess() << "\n";
}
