#include "sequence_counter_aft_max.hpp"
#include <limits>
#include <stdexcept>

stepanov::SequenceCounterAftMax::SequenceCounterAftMax():
  maxElement_(0),
  countAfterMax_(0),
  max_size_(0),
  count_(0)
{}

void stepanov::SequenceCounterAftMax::counter(int current_number)
{
  ++count_;
  const size_t max_size_ = std::numeric_limits< size_t >::max();
  if (count_ == max_size_)
  {
    throw std::logic_error("Sequence is too long");
  }
  if (current_number > maxElement_)
  {
    maxElement_ = current_number;
    countAfterMax_ = 0;
  }
  else
  {
    countAfterMax_++;
  }
}

size_t stepanov::SequenceCounterAftMax::get_result() const
{
  return countAfterMax_;
}
