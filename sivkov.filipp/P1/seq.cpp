#include "seq.hpp"
#include <limits>
#include <stdexcept>
sivkov::SequenceCount::SequenceCount():
  k1(0)
{}

void sivkov::SequenceCount::operator()(int num, int num_old)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (k1 == max_size)
  {
     throw std::logic_error("seq is to long");
  }
  if (num_old % num == 0)
  {
    ++k1;
  }
}
size_t sivkov::SequenceCount::operator()() const
{
  return k1-1;
}
