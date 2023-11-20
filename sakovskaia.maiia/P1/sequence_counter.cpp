#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

sakovskaia::SequenceSignsCounter::SequenceSignsCounter():
  lastNumber(0),
  count_(0)
{}

void sakovskaia::SequenceSignsCounter::operator()(int number_)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if ((number_ > 0 && lastNumber < 0) || (number_ < 0 && lastNumber > 0))
  {
    if (count_ > max_size)
    {
      throw std::logic_error("Sequence is too long");
    }
    if (count_ == 1 && lastNumber == 0)
    {
      throw std::logic_error("Sequence is too short");
    }
    ++count_;
  }
  lastNumber = number_;
}

size_t sakovskaia::SequenceSignsCounter::operator()() const
{
  return count_;
}

