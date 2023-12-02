#include "sequence_counter_aft_max.hpp"
#include <limits>
#include <stdexcept>

stepanov::SequenceCounterAftMax::SequenceCounterAftMax():
  maxElement_(0),
  countAfterMax_(0),
  count_(0),
  isFirst_(0)
{}

void stepanov::SequenceCounterAftMax::counter(int current_number)
{
  ++count_;
  if (current_number == 0 && count_ == 1)
  {
    throw std::logic_error("The amount of AFT-MAX cannot be certain");
  }
  const size_t maxSize_ = std::numeric_limits< size_t >::max();
  if (count_ == maxSize_)
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

size_t stepanov::SequenceCounterAftMax::getResult() const
{
  return countAfterMax_;
}
