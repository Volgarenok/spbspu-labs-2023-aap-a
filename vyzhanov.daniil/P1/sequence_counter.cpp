#include <iostream>
#include <limits>
#include <stdexcept>
#include "sequence_counter.hpp"

vyzhanov::SequenceCounter::SequenceCounter():  count(1), maxi_num(0), after_max(0)
{}

void vyzhanov::SequenceCounter::operator()(int num)
{
   size_t max_s = std::numeric_limits< size_t >::max();
    if (count == max_s)
    {
      throw  std::logic_error("Sequence is too long!\n");
    }

    if (num == 0)
    {
      count--;
      if(count == 0)
      {
        throw  std::logic_error("Sequence is too short!\n");
      }

    }
    else if(count < max_s)
    {
      if (num > maxi_num)
      {
        maxi_num = num;
        after_max = 0;
      }

      else if (num <= maxi_num)
      {
        ++after_max;
      }

      ++count;
    }

}
size_t vyzhanov::SequenceCounter::operator()() const
{
  return after_max;
}

