#include "composition.hpp"
#include <stdexcept>
#include <iostream>

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
        spec.Counter(num);
        spec.Sum(num);
        spec.MoreLess(num);
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
    spec.Counter();
    spec.Sum();
    spec.MoreLess();
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  std::cout << spec.Counter() << "\n";
  std::cout << spec.Sum() << "\n";
  std::cout << spec.MoreLess() << "\n";
}
