#include <iostream>
#include "sequence_counter.hpp"
#include "frist_second_sum.hpp"
#include <stdexcept>

int main()
{
  int num = 0;
  using namespace vyzhanov;
  using namespace vyzhanov1;
  SequenceCounter counter;
  Sum sum;
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

  if (num == 0)
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
    std::cout << counter() << "\n";
    std::cout << sum() << "\n";
  }
}
