#include "loc_max_counter.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  using namespace lopatina;
  Loc_Max_Counter counter;

  int number = 0;
  std::cin >> number;
  if (!std::cin) {
    std::cerr << "Is not a sequence\n";
    return 1;
  }


  if (number != 0) {
    while (number != 0) {
      try
      {
        counter(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << e.what();
        return 2;
      }

      std::cin >> number;
      if (!std::cin) {
        std::cerr << "Is not a sequence\n";
        return 1;
      }
    }
  } else {
    std::cerr << "Sequence is too short\n";
    return 2;
  }
  try
  {
    std::cout << counter.() << "\n";
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what();
    return 2;
  }
}
