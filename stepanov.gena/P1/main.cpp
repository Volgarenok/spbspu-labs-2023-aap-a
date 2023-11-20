#include <iostream>
#include <stdexcept>
#include "sequence_counter_mon_inc.hpp"
#include "sequence_counter_aft_max.hpp"

int main()
{
  int current_number = 0;
  size_t isFirst = 0;
  using namespace stepanov;
  SequenceCounterMonInc count;
  SequenceCounterAftMax count_aft;
  do
  {
    ++isFirst;
    std::cin >> current_number;
    if (current_number == 0 && isFirst == 1)
    {
      std::cout << "The amount of AFT-MAX cannot be certain\n";
      return 2;
    }
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    else if (current_number != 0)
    {
      try
      {
        count.counter(current_number);
        count_aft.counter(current_number);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (current_number != 0);
  std::cout << "[MON-INC]" << "=" << count.get_result() << "\n";
  std::cout << "[AFT-MAX]" << "=" << count_aft.get_result() << "\n";
}
