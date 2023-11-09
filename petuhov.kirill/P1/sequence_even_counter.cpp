#include "sequence_even_counter.hpp"
#include <cstddef>
#include <limits>
#include <stdexcept>

petuhov::SequenceEvenCounter::SequenceEvenCounter():
  temp_count_(0),
  max_count_(0)
{}

void petuhov::SequenceEvenCounter::operator()(int num)
{
  size_t max_size = std::numeric_limits< size_t >::max();

  if (num % 2 == 0)
  {
    if (temp_count_ == max_size)
    {
      throw std::logic_error("Sequence is too long");
    }
    ++temp_count_;
    max_count_ = max_count_ < temp_count_ ? temp_count_ : max_count_;
  }
  else
  {
    temp_count_ = 0;
  }
}

size_t petuhov::SequenceEvenCounter::operator()() const
{
  return max_count_;
}
