#include <iostream>
#include <stdexcept>

#include "PythTripleCounter.hpp"
#include "DivWithoutRemCounter.hpp"

int main()
{
  int num = 0;
  agarkov::PythTripleCounter pyth_triple_counter;
  agarkov::DivWithoutRemCounter div_without_rem_counter;
  do
  {
    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 2;
    }
    else if (num != 0)
    {
      pyth_triple_counter(num);
      try
      {
        div_without_rem_counter(num);
      }
      catch (const std::logic_error& e)
      {
        std::cout << e.what() << "\n";
        return 0;
      }
    }
  }
  while (num != 0);
  std::cout << pyth_triple_counter.getCount() <<"\n";
  std::cout << div_without_rem_counter.getCount() <<"\n";
}
