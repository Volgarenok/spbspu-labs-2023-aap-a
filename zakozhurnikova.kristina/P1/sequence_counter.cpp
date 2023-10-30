#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

zakozhurnikova::SequenceCounter::SequenceCounter():
   counts(0)
  {}

  void zakozhurnikova::SequenceCounter::count(int number)
  {
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
  size_t zakozhurnikova::SequenceCounter::get_result() const
  {
    return counts;
  }
