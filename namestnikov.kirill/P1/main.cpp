#include <iostream>
#include <stdexcept>
#include "local_min_counter.hpp"

int main()
{
  int lastnumber = 0;
  using namespace namestnikov;
  LocalMinCounter counter;
  std::cin >> lastnumber;
  if (!std::cin)
  {
    std::cerr << "Is not a  sequence\n";
    return 1;
  }
  else if (lastnumber == 0)
  {
    std::cerr << "There is no way to find a local min\n";
    return 2;
  }
  int currentnumber = 0;
  std::cin >> currentnumber;
  if (!std::cin)
  {
    std::cerr << "Is not a  sequence\n";
    return 1;
  }
  else if (currentnumber == 0)
  {
    std::cerr << "There is no way to find a local min\n";
    return 2;
  }
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
      counter.count(lastnumber, currentnumber, futurenumber);
    }
    catch (const std::exception & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      return 2;
    }
    lastnumber = currentnumber;
    currentnumber = futurenumber;
    std::cin >> futurenumber;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
  }
  std::cout << counter.get_result() << "\n";
}
