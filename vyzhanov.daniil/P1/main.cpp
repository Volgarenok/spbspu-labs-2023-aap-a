#include <iostream>
#include "sequence_counter.hpp"
#include <stdexcept>

int main()
{
  int num = 0;
  SequenceCounter counter;
  do
  {
    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "Is not a sequance\n";
      return 1;
    }
    else if (num != 0)
    {
      try
      {
        counter.size(num);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }

  while (num != 0);
  std::cout << counter.get_res() << "\n";
}
