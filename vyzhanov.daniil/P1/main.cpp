#include "sequence_counter.hpp"
#include "first_second_sum.hpp"
#include <stdexcept>
#include <iostream>

int main()
{
  int num = 0;
  using namespace vyzhanov;
  CountAfterMax counter;
  SumDup sum;
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
        counter(num);
        sum(num);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (num != 0);
  try
  {
    counter();
    sum();
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  std::cout << counter() << "\n";
  std::cout << sum() << "\n";
}
