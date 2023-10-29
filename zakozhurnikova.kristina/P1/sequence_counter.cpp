#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

  SequenceCounter::SequenceCounter():
   counts(0)
  {}

  void SequenceCounter::count(int number)
  {
    int max = std::numeric_limits< int >::min();
    size_t max_size = std::numeric_limits< size_t >::max();
    if (counts == max_size)
    {
      throw std::logic_error("sequence is too long");
    }
    else if (number > max)
    {
      counts = 0;
      max = number;
    }
    else
    {
      ++counts;
    }
  }
  size_t SequenceCounter::get_result() const
  {
    return counts;
  }
