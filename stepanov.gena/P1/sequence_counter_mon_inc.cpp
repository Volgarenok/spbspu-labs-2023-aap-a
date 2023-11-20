#include "sequence_counter_mon_inc.hpp"
#include <limits>
#include <stdexcept>

stepanov::SequenceCounterMonInc::SequenceCounterMonInc():
  last_number_(0),
  current_count_(0),
  max_count_(0),
  max_size_(0)
{}
void stepanov::SequenceCounterMonInc::counter(size_t current_number)
{
  const size_t max_size_ = std::numeric_limits< size_t >::max();
  if (current_count_ == max_size_)
  {
    throw std::logic_error("Sequence is too long\n");
  }
  if (last_number_ <= current_number)
  {
    last_number_ = current_number;
    ++current_count_;
    if (current_count_ > max_count_)
    {
      max_count_ = current_count_;
    }
  }
  else
  {
    last_number_ = current_number;
    current_count_ = 1;
  }
}

size_t stepanov::SequenceCounterMonInc::get_result() const
{
  return max_count_;
}
