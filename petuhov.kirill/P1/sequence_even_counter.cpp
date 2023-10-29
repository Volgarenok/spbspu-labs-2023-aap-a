#include <cstddef>
#include <limits>
#include <stdexcept>
#include "sequence_even_counter.hpp"

petuhov::SequenceEvenCounter::SequenceEvenCounter():
 temp_count(0),
 max_count(0)
{}

void petuhov::SequenceEvenCounter::operator()(int num)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  
  if (num % 2 == 0)
  {
    if (temp_count == max_size)
    {
      throw std::logic_error("Sequence is too long");
    }

    ++temp_count;
    max_count = max_count < temp_count ? temp_count : max_count;
  }
  else
  {
    temp_count = 0;
  }
}

size_t petuhov::SequenceEvenCounter::operator()() const
{
  return max_count;
}
