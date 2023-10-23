#include <iostream>
#include <stdexcept>

#include "counter.hpp"

int main()
{
  int prev = 0;
  int curr = 0;
  using namespace zhalilov;
  Counter counter;
  while(std::cin >> curr && curr)
  {
    try
    {
      counter(prev, curr);
    }
    catch(std::exception &e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      return 1;
    }
    prev = curr;
  }

  if(!std::cin)
  {
    std::cout << "Bad input";
    return 1;
  }

  std::cout << counter() << "\n";
}
