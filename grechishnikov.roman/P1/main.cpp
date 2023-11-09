#include <iostream>
#include <stdexcept>
#include <cstddef>
#include "sequence_count_min.hpp"

int main()
{
  using namespace grechishnikov;
  SequenceCountMin seq;
  long long num = 0;
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
        seq(num);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (num != 0);
  std::cout << seq() << "\n";
}
