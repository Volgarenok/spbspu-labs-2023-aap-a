#include <iostream>
#include "sequence_counter.hpp"
#include "ismax.hpp"
#include "chet_counter.hpp"

int main()
{
  int number = 0;
  int actual_max = 0;
  int pre_max = 0;
  size_t max_chet_count = 0;
  size_t current_chet_count = 0;
  using namespace nikitov;
  SequenceCounter counter;

  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Error: This is not a sequence\n";
      return 1;
    }
    else if (number != 0)
    {
      try
      {
        counter(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << '\n';
        return 2;
      }
      isMax(number, actual_max, pre_max);
      chet_counter(number, max_chet_count, current_chet_count);
    }
  }
  while (number != 0);

  std::cout << max_chet_count << '\n';
  if (counter() == 0 || counter() == 1)
  {
    std::cerr << "Error: This sequence is too short for SUB-MAX\n";
    return 2;
  }
  std::cout << pre_max << '\n';
  return 0;
}
