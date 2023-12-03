#include "counterofnums.hpp"
#include <limits>
#include <stdexcept>

arakelyan::CounterOfNumsThatDevideByThePrev::CounterOfNumsThatDevideByThePrev():
  count_(0),
  pastNum_(0)
{}

void arakelyan::CounterOfNumsThatDevideByThePrev::counterOfSequence(int current)
{
  size_t maxSize = std::numeric_limits< size_t >::max();
  if ((pastNum_ != 0) && (current % pastNum_ == 0))
  {
    if (count_ == maxSize)
    {
      throw std::overflow_error("Sequence is too long!");
    }
    ++count_;
  }

  pastNum_ = current;
}

size_t arakelyan::CounterOfNumsThatDevideByThePrev::getCount() const
{
  if (pastNum_ == 0)
  {
    throw std::logic_error("Sequence is too short!");
  }
  else
  {
    return count_;
  }
}
