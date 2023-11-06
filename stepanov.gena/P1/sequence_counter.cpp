#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

stepanov::SequenceCounter::SequenceCounter():
  max_count(0),
  last(0),
  count_(0),
  c(0)
{}

void stepanov::SequenceCounter::operator()(int number)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (c == max_size)
  {
    throw std::logic_error("Sequence is too long");
  }
  if (number >= last)
  {
    last = number;
    count_ = count_ + 1;
    ++c;
    if (count_ > max_count)
    {
      max_count = count_;
    }
  } else if (number < last) {
    last = number;
    if (count_ > max_count)
    {
      max_count = count_;
    }
    count_ = 0;
    count_ = count_ + 1;
    ++c;
  }
}

size_t stepanov::SequenceCounter::operator()() const
{
  return max_count;
}
