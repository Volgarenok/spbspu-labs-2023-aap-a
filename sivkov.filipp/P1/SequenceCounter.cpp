#include "SequenceCounter.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

sivkov::SequenceCounter::SequenceCounter():
  k_(0),
  num_(0),
  num_old_(0)
{}

void sivkov::SequenceCounter::operator()(int num)
{
  num_ = num;
  size_t max_size = std::numeric_limits< size_t >::max();
  if (num_ != 0)
  {
    if (num_old_ % num_ == 0)
    {
      ++k_;
    }
    num_old_ = num;
    if (k_ == max_size)
    {
      throw std::logic_error("Sequence is to long...");
    }
  }
}
size_t sivkov::SequenceCounter::operator()() const
{
  return k_ - 1;
}
