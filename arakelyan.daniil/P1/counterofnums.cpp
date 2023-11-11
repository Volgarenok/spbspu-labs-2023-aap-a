#include "counterofnums.hpp"
#include <limits>
#include <stdexcept>

arakelyan::CounterOfNumsThatDevideByThePrev::CounterOfNumsThatDevideByThePrev():
  count_(0),
  pastNum_(0),
  length_(0),
  currentNum_(0)
{}

void arakelyan::CounterOfNumsThatDevideByThePrev::operator()(int current)
{
  length_++;
  currentNum_ = current;
  size_t maxSize = std::numeric_limits< size_t >::max();

  if ((pastNum_ != 0) && (currentNum_ % pastNum_ == 0))
  {
    ++count_;
  }
  pastNum_ = currentNum_;
  if (length_ > maxSize)
  {
    throw std::logic_error("Sequence is too long!");
  }
}

size_t arakelyan::CounterOfNumsThatDevideByThePrev::operator()() const
{
  if ((length_ == 1 && pastNum_ == 0) || (length_ == 0) || (length_ == 1 && count_ == 0))
  {
    throw std::logic_error("Sequence is too short!");
  }
  return count_;
}
