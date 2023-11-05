#include "local_max_counter.hpp"
#include <limits>
#include <stdexcept>

baranov::LocalMaxCounter::LocalMaxCounter():
  prevNumber_(0),
  currentNumber_(0),
  nextNumber_(0),
  count_(0)
{}

void baranov::LocalMaxCounter::operator()(long long int number)
{
  if (prevNumber_ == 0)
  {
    prevNumber_ = number;
  }
  else if (currentNumber_ == 0)
  {
    currentNumber_ = number;
  }
  else
  {
    nextNumber_ = number;
    if (currentNumber_ > prevNumber_ && currentNumber_ > nextNumber_)
    {
      size_t max_size = std::numeric_limits< size_t >::max();
      if (count_ == max_size)
      {
        throw std::logic_error("sequence is too long");
      }
      ++count_;
    }
    prevNumber_ = currentNumber_;
    currentNumber_ = nextNumber_;
  }
}

size_t baranov::LocalMaxCounter::operator()() const
{
  if (prevNumber_ == 0)
  {
    throw std::logic_error("sequence is too short");
  }
  return count_;
}

