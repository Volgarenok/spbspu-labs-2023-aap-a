#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>
stepanov::SequenceCounter::SequenceCounter():
  count_(0)
{}

void stepanov::SequenceCounter::operator()(int)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (count_ == max_size)
  {
    throw std::logic_error("Sequence is too long");
  }
  ++count_;
}
size_t stepanov::SequenceCounter::operator()() const
{
  return count_;
}

