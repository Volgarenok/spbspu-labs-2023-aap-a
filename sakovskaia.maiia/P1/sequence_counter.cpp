#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

sakovskaia::SequenceSignsCounter::SequenceSignsCounter():
  last_number_(0),
  count_(0)
{}

void sakovskaia::SequenceSignsCounter::operator()(int number)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if ((number > 0 && last_number_ < 0) || (number < 0 && last_number_ > 0))
  {
    if (count_ == max_size)
    {
      throw std::logic_error("Sequence is too long");
    }
    ++count_;
  }
  last_number_ = number;
}

size_t sakovskaia::SequenceSignsCounter::operator()() const
{
  if (count_ == 0 && last_number_ == 0)
  {
    throw std::logic_error("Sequence is too short");
  }
  return count_;
}

