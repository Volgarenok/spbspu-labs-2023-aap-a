#include <limits>
#include <stdexcept>
#include "Sequence_counterMax.hpp"

novokhatskiy::SequenceCounterMax::SequenceCounterMax():
  count_(0),
  max_(0)
{}
void novokhatskiy::SequenceCounterMax::operator()(int num)
{
  const size_t max_size = std::numeric_limits< size_t >::max();
  if (num > max_)
  {
    max_ = num;
    count_ = 0;
  }
  else
  {
    ++count_;
    if (1 + count_ == 0)
    {
      throw std::logic_error("The sequence is too long!");
    }
  }
}

size_t novokhatskiy::SequenceCounterMax::operator()() const
{
  return count_;
}
