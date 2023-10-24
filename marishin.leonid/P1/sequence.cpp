#include "sequence.hpp"
#include <limits>
#include <stdexcept>
#include <iostream>

marishin::Sequence::Sequence():
  global_count(0),
  prev1(0),
  prev2(0),
  count(0)
{}

void marishin::Sequence::operator()(int num)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (global_count == max_size)
  {
    throw std::logic_error("sequence is too long");
  }
  if ((global_count > 2) && (num == prev1 + prev2))
  {
    count++;
  }
  prev2 = prev1;
  prev1 = num;
  ++global_count;
}
