#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

sakovskaia::SequenceSignsCounter::SequenceSignsCounter():
  count_(0)
{}

void sakovskaia::SequenceSignsCounter::operator()(size_t size, int curr)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (size > max_size)
  {
    throw std::logic_error("Sequence is too long");
  }
  if (size == 1 && curr == 0)
  {
    throw std::logic_error("Sequence is too short");
  }
}

void sakovskaia::SequenceSignsCounter::operator()(int a, int b)
{
  if ((a > 0 && b < 0) || (a < 0 && b > 0))
  {
    ++count_;
  }
}
size_t sakovskaia::SequenceSignsCounter::operator()() const
{
  return count_;
}

