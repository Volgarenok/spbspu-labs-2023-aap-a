#include <iostream>
#include <stdexcept>
#include <cstddef>
#include "sequence.hpp"

int main()
{
  sequence seq;
  long long num;
  do
  {
    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "Not a sequence\n";
      return 1;
    }
    if (num != 0)
    {
      try
      {
        seq.doCount(num);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (num != 0);
  std::cout << seq.getRez() << "\n";
}
