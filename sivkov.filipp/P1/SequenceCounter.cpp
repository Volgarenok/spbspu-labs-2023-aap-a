#include "SequenceCounter.hpp"
#include <limits>
#include <stdexcept>

sivkov::SequenceCount::SequenceCount():
  k_(0)
{}

void sivkov::SequenceCount::operator()(int num, int num_old)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (k_ == max_size)
  {
     throw std::logic_error("seq is to long");
  }
  if (num_old % num == 0)
  {
    ++k_;
  }
}
size_t sivkov::SequenceCount::operator()() const
{
  return k_-1;
}
