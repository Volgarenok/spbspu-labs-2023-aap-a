#include <iostream>
#include <stdexcept>
#include "CountIfDivideWithoutRemaining.hpp"

int main()
{
  int num = 1;

  using namespace sivkov;
  CountIfDivideWithoutRemaining counter;

  do
  {
    std::cin >> num;

    if (!std::cin)
    {
      std::cerr << "is not a seq...\n";
      return 1;
    }
    else if (num != 0)
    {

      try
      {
        counter(num);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (num != 0);
  std::cout << "Answer: " << counter() << "\n";
}
