#include <iostream>
#include <stdexcept>
#include "local_min_counter.hpp"

int main()
{
  using namespace namestnikov;
  LocalMinCounter counter;
  int futurenumber = 0;
  std::cin >> futurenumber;
  if (!std::cin)
  {
    std::cerr << "Is not a  sequence\n";
    return 1;
  }
  else if (futurenumber == 0)
  {
    std::cerr << "There is no way to find a local min\n";
    return 2;
  }
  while (futurenumber != 0)
  {
    try
    {
      counter(futurenumber);
    }
    catch (const std::exception & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      return 2;
    }
    std::cin >> futurenumber;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
  }
  std::cout << counter() << "\n";
}
