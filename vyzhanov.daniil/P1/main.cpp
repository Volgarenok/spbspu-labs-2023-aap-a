#include "sequence_counter.hpp"
#include "first_second_sum.hpp"
#include "more_less_check.hpp"
#include <stdexcept>
#include <iostream>

struct SequenceSpec
{
  vyzhanov::CountAfterMax counter;
  vyzhanov::SumDup sum;
  vyzhanov::MoreAndLess moreless;

  void operator()(int num)
  {
    return counter(num), sum(num), moreless(num);
  }

  size_t operator()()
  {
    return counter(), sum(), moreless();
  }
};

int main()
{
  SequenceSpec spec;
  int num = 0;
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
        spec(num);
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
    spec();
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  std::cout << spec() << "\n";
}
