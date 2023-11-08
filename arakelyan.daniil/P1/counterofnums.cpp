#include <iostream>
#include "counterofnums.hpp"
#include <limits>

arakelyan::CounterOfNumsThatDevideByThePrev::CounterOfNumsThatDevideByThePrev():
  count_(0),
  length_(0),
  pastNum_(0)
{}

void arakelyan::CounterOfNumsThatDevideByThePrev::operator()(int currentNum)
{
  length_++;
  size_t maxLength = std::numeric_limits< size_t >::max();

  if (currentNum != 0)
  {
    if ((pastNum_ != 0) && (currentNum % pastNum_ == 0))
    {
      ++count_;
    }
    pastNum_ = currentNum;
    if (length_ == maxLength)
    {
      throw std::logic_error("Sequense is too long");
    }
  }
  else if ((length_ == 2 && currentNum == 0) || (length_ == 1 && currentNum == 0))
  {
    throw std::logic_error("Sequence is too short");
  }
}

size_t arakelyan::CounterOfNumsThatDevideByThePrev::operator()() const
{
  return count_;
}
