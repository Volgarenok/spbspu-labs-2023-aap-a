#include <iostream>
#include <stdexcept>
#include "loc_max_counter.hpp"
#include "sum_dup_counter.hpp"

int main()
{
  using namespace prisyach;
  LocMaxCounter counter;
  SumDupCounter counter2;

  int number = 0;
  std::cin >> number;
  if (!std::cin) {
    std::cerr << "Is not a sequence\n";
    return 1;
  }

  while (number != 0) {
    try {
      counter(number);
      counter2(number);
    }
    catch (const std::exception & e) {
      std::cerr << e.what();
      return 2;
    }

    std::cin >> number;
    if (!std::cin) {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
  }

  try {
    std::cout << counter() << '\n';
    std::cout << counter2() << '\n';
  }
  catch (const std::exception & e) {
    std::cerr << e.what();
    return 2;
  }
}
