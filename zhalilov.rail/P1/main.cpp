#include <iostream>
#include "counter.hpp"

int main()
{
  int prev = 0;
  int curr = 0;
  using namespace zhalilov;
  Counter counter;
  while(std::cin >> curr && curr)
  {
    counter(prev, curr);
    prev = curr;
  }

  if(!std::cin.good())
  {
    std::cout << "Bad input";
    return 1;
  }

  std::cout << counter();
}
