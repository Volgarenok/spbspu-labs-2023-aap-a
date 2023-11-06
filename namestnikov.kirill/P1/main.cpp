#include <iostream>
#include <stdexcept>
#include "local_min_counter.hpp"

int main()
{
  using namespace namestnikov;
  LocalMinCounter counter;
  int futureNumber = 0;
  do
  {
    std::cin >> futureNumber;
    if (!std::cin)
    {
      std::cerr << "Is not a  sequence\n";
      return 1;
    }
    try
    {
      counter(futureNumber);
    }
    catch (const std::exception & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      return 2;
    }
  }
  while (futureNumber != 0);
  std::cout << counter() << "\n";
}
