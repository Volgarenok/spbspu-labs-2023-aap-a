#include <limits>
#include <stdexcept>
#include "Sequence_counter.hpp"

novokhatskiy::SequenceCounter::SequenceCounter():
  count_(0),
  max_(0)
{}
void novokhatskiy::SequenceCounter::operator()(int num)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (count_ == max_size)
  {
    throw std::logic_error("Sequence is too long");
  }
  else if (num > max_)
  {
    max_ = num;
    count_ = 0;
  }
  else
  {
    ++count_;
  }
}
size_t novokhatskiy::SequenceCounter::operator()() const
{
  return count_;
}
