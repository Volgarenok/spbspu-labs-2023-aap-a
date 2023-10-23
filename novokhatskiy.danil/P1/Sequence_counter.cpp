#include "Sequence_counter.hpp"
#include <limits>
#include <stdexcept>

SequenceCounter::Sequence():
  count_(0)
{}
void SequenceCounter::count(int)
{
  size_t max_size = std::numeric_limits size_t >::max();
  if (count_ == max_size)
  {
    throw std::logic_error("Sequence is too long");
  }
  if (num > max)
  {
    max = num;
    count_ = 0;
  }
  else
  {
    ++count_;
  }
}
size_t SequenceCounter::get_result() const
{
  return count_;
}
