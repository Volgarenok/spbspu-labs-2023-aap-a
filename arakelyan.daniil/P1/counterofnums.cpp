#include "counterofnums.hpp"
#include <limits>
#include <stdexcept>

arakelyan::CounterOfNumsThatDevideByThePrev::CounterOfNumsThatDevideByThePrev():
  count_(0),
  pastNum_(0),
  length_(0),
  currentNum_(0)
{}

void arakelyan::CounterOfNumsThatDevideByThePrev::counterOfSequence(int current)
{
  currentNum_ = current;
  size_t maxSize = std::numeric_limits< size_t >::max();
  if (length_ == maxSize)
  {
    throw std::logic_error("Sequence is too long!");
  }
  length_++;
  if ((pastNum_ != 0) && (current % pastNum_ == 0))
  {
    ++count_;
  }

  pastNum_ = current;
}

void arakelyan::CounterOfNumsThatDevideByThePrev::chekZeroSequence(size_t curr)
{
  if (((curr != currentNum_) && length_ == 1))
  {
    throw std::logic_error("Sequence is toooo short!");
  }
}

size_t arakelyan::CounterOfNumsThatDevideByThePrev::get_count() const
{
  return count_;
}
