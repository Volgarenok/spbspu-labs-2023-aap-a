#include <iostream>
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
      std::cerr << "sequence is not valid";
      return 1;
    }

    if (number != 0)
    {
      size_t max_size = std::numeric_limits<size_t>::max();
      if (size == max_size)
      {
        std::cerr << "sequence is too long";
        return 2;
      }
      size++;

      signChangeCounter(number);
      localMaxCounter(number);
    }
  }
  while (number != 0);

  if (size == 0)
  {
    std::cerr << "sequence is too short";
    return 2;
  }

  std::cout << signChangeCounter() << '\n';
  std::cout << localMaxCounter() << '\n';

  return 0;
}
