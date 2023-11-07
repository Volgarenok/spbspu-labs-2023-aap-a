#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

nikitov::SequenceCounter::SequenceCounter():
  actualMax_(0),
  prevMax_(0),
  count_(0)
{}

void nikitov::SequenceCounter::operator()(long long int number)
{
  size_t max_limit = std::numeric_limits< size_t >::max();
  if (count_ == max_limit)
  {
    throw std::logic_error("This sequence has no end");
  }
  ++count_;

  if (number >= actualMax_)
  {
    prevMax_ = actualMax_;
    actualMax_ = number;
  }
  else if (number > prevMax_)
  {
    prevMax_ = number;
  }
}
long long int nikitov::SequenceCounter::operator()() const
{
  if (count_ < 2)
  {
    throw std::logic_error("This sequence is too short");
  }
  return prevMax_;
}
