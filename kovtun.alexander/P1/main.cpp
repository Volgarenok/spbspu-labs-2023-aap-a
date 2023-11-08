#include <iostream>
#include <limits>

#include "sign_change_counter.hpp"


int main()
{
  int number = 0;
  size_t size = 0;

  kovtun::SignChangeCounter signChangeCounter;

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
    }
  }
  while (number != 0);

  try
  {
    std::cout << signChangeCounter() << '\n';
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 2;
  }

  return 0;
}

