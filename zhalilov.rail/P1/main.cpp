#include <iostream>
#include <stdexcept>

#include "MaxEqualSeqCounter.hpp"

int main()
{
  using namespace zhalilov;
  MaxEqualSeqCounter counter;
  int curr = 0;
  while ((std::cin >> curr) && curr)
  {
    try
    {
      counter(curr);
    }
    catch (const std::exception &e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      return 1;
    }
  }

  if (!std::cin)
  {
    std::cerr << "Error: bad input\n";
    return 1;
  }

  std::cout << counter() << "\n";
}
