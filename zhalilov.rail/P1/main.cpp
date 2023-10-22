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
    if(!std::cin)
    {
      std::cout << "Bad input";
      return 1;
    }
    counter(prev, curr);
    prev = curr;
  }

  std::cout << counter();
}
