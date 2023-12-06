#include <stdexcept>
#include <iostream>
#include "CompositionOfCharacteristics.hpp"

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
    std::cout << spec.checkMoreLess() << "\n";
    std::cout << spec.getCount() << "\n";
    std::cout << spec.getSum() << "\n";
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
}
