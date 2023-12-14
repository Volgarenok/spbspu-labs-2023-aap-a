#include "sequence_counter_mon_inc.hpp"
#include <limits>
#include <stdexcept>

stepanov::SequenceCounterMonInc::SequenceCounterMonInc():
  lastNumber_(0),
  currentCount_(0),
  maxCount_(0)
{}
void stepanov::SequenceCounterMonInc::counter(size_t current_number)
{
  const size_t max_size = std::numeric_limits< size_t >::max();
  if (lastNumber_ <= current_number)
  {
    lastNumber_ = current_number;
    if (max_size - currentCount_ < 1)
    {
      throw std::logic_error("Sequence addition would cause overflow");
    }
    currentCount_ += 1;
    if (currentCount_ > maxCount_)
    {
      maxCount_ = currentCount_;
    }
  }
  else
  {
    lastNumber_ = current_number;
    currentCount_ = 1;
  }
}

size_t stepanov::SequenceCounterMonInc::getResult() const
{
  return maxCount_;
}
