#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

SequenceCounter::SequenceCounter():
    count_(0)
{}

void SequenceCounter::isLimit(int)
{
  size_t max_limit = std::numeric_limits< size_t >::max();
  if (count_ == max_limit){
    throw std::logic_error("This sequence has no end\n");
  }
  ++count_;
}
size_t SequenceCounter::check_count() const
{
  return count_;
}
