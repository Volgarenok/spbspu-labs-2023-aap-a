#include <iostream>
#include <cstddef>
#include <limits>

#include "sign_change_counter.hpp"
#include "local_max_counter.hpp"


int main()
{
  int number = 0;

  kovtun::SignChangeCounter signChangeCounter;
  kovtun::LocalMaxCounter localMaxCounter;

  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "sequence is not valid\n";
      return 1;
    }

    if (number != 0)
    {
      try
      {
        signChangeCounter(number);
        localMaxCounter(number);
      }
      catch (const std::overflow_error & e)
      {
        std::cerr << e.what() << '\n';
        return 2;
      }
    }
  }
  while (number != 0);

  std::cout << signChangeCounter() << '\n';
  std::cout << localMaxCounter() << '\n';

  return 0;
}
