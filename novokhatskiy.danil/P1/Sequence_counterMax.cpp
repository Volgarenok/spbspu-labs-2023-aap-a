#include "Sequence_counterMax.hpp"
#include <limits>
#include <stdexcept>

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
    if (count_ == max_size)
    {
      throw std::logic_error("The sequence is too long!");
    }
    ++count_;
  }
}

size_t novokhatskiy::SequenceCounterMax::operator()() const
{
  return count_;
}
