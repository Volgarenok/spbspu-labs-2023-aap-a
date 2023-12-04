#include <iostream>
#include <cstddef>
#include <limits>

#include "sign_change_counter.hpp"
#include "local_max_counter.hpp"


int main()
{
  int number = 0;
  size_t size = 0;

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
      size_t max_size = std::numeric_limits<size_t>::max();
      if (size == max_size)
      {
        std::cerr << "sequence is too long\n";
        return 2;
      }
      size++;

      try
      {
        signChangeCounter(number);
        localMaxCounter(number);
      }
      catch(std::overflow_error &e)
      {
        std::cerr << e.what() << '\n';
        return 2;
      }
    }
  }
  while (number != 0);

  if (size == 0)
  {
    std::cerr << "sequence is too short\n";
    return 2;
  }

  std::cout << signChangeCounter() << '\n';
  std::cout << localMaxCounter() << '\n';

  return 0;
}
