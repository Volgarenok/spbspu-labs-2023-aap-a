#include <iostream>
#include "moninc.hpp"

int main()
{
  using namespace spiridonov;
  int num;
  Moninc count;
  do
  {
    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "Cannot identify a monotonically increasing fragment in the sequence\n";
      return 1;
    }
    else if (num != 0)
    {
      try
      {
        count(num);
        count();
      }
      catch (std::exception& e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (num != 0);
  std::cout << "\nMaximum length of a monotonically increasing fragment:" << count.output() << "\n";
}
