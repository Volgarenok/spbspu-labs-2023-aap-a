#include <iostream>
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
  size_t maxLength = std::numeric_limits< size_t >::max();

  if (currentNum_ != 0)
  {
    if ((pastNum_ != 0) && (currentNum_ % pastNum_ == 0))
    {
      ++count_;
    }
    pastNum_ = currentNum_;
    if (length_ == maxLength)
    {
      throw std::logic_error("Sequense is too long");
    }
  }
}

size_t arakelyan::CounterOfNumsThatDevideByThePrev::operator()() const
{
  if ((length_ == 1 && currentNum_ == 0) || (length_ == 2 && currentNum_ == 0))
  {
    throw std::logic_error("Sequence is too short");
  }
  return count_;
}
