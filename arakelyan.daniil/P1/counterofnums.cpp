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
    throw std::overflow_error("Sequence is too long!");
  }
  length_++;
  if ((length_ >= 2) && (current % pastNum_ == 0))
  {

    if (count_ == maxSize)
    {
      throw std::overflow_error("Counter is out of the range!");
    }
    ++count_;
  }

  pastNum_ = current;
}

void arakelyan::CounterOfNumsThatDevideByThePrev::chekZeroSequence(size_t curr)
{
  if (((curr != currentNum_) && length_ == 1) || ((curr == currentNum_) && length_ == 0))
  {
    throw std::logic_error("Sequence is to short!");
  }
}

size_t arakelyan::CounterOfNumsThatDevideByThePrev::get_count() const
{
  return count_;
}
