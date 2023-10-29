#include <iostream>
#include "mondec.h"

int main()
{
  using namespace strelyaev;
  int currentNumber = 0;
  Mondec count;

  do
  {
    std::cin >> currentNumber;
    if (!std::cin)
    {
      std::cerr << "AN ERROR HAS OCCURRED: NOT A NUMBER\n";
      return 1;
    }
    else if (currentNumber != 0)
    {
      try
      {
        count(currentNumber);
      }
      catch (const std::logic_error & e)
      {
        std::cerr << "ERROR: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (currentNumber != 0);
  std::cout << count() << "\n";
}
