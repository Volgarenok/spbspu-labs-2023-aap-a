#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

sakovskaia::SequenceCounter::SequenceCounter():
  count_(0)
{}

void sakovskaia::SequenceCounter::operator()(size_t size, int curr)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (size == max_size)
  {
    throw std::logic_error("Sequence is too long\n");
  }
  if (size == 1 && curr == 0)
  {
    throw std::logic_error("Sequence is too short\n");
  }
}

void sakovskaia::SequenceCounter::operator()(int a, int b)
{
  if ((a > 0 && b < 0) || (a < 0 && b > 0))
  {
    ++count_;
  }
}
size_t sakovskaia::SequenceCounter::operator()() const
{
  return count_;
}

