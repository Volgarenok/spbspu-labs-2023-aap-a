#include <iostream>
#include <stdexcept>
#include <limits>
#include "pyth_triples_counter.hpp"

int main()
{
  int current = 0;
  using namespace erohin;
  PythTriplesCounter pythtriples;
  do
  {
    std::cin >> current;
    if (!std::cin)
    {
      std::cerr << "Input data is not a number sequence\n";
      return 1;
    }
    else if (current != 0)
    {
      try
      {
        pythtriples(current);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (current != 0);
  std::cout << pythtriples() << "\n";
}
