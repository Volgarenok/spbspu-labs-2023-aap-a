#include <iostream>
#include <limits>
#include <stdexcept>
#include "EVEN_COUNTER.hpp"

int main()
{
  isaychev::even_counter counter1;
  int c_number = 0;
  std::cin >> c_number;
  if (!std::cin)
  {
    std::cerr << "not a number was inputed\n";
    return 1;
  }
  while (c_number != 0)
  {
    try
    {
      counter1.evn_cnt(c_number);
    }
    catch (const std::exception & e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
    std::cin >> c_number;
    if (!std::cin)
    {
      std::cerr << "not a number was inputed\n";
      return 1;
    }
  }
  std::cout << counter1.get_res() << "\n";
}


