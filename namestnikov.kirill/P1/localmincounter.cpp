#include "local_min_counter.hpp"
#include <limits>
#include <stdexcept>

namestnikov::LocalMinCounter::LocalMinCounter():
  count_(0),
  lastNumber_(0),
  currentNumber_(0)
{}

void namestnikov::LocalMinCounter::operator()(int futureNumber)
{
  const size_t max_size = std::numeric_limits< size_t >::max();
  if ((currentNumber_ < lastNumber_) && (currentNumber_ < futureNumber))
  {
    if (count_ == max_size)
    {
      throw std::logic_error("sequence is too long\n");
    }
    ++count_;
  }
  lastNumber_ = currentNumber_;
  currentNumber_ = futureNumber;
}
size_t namestnikov::LocalMinCounter::operator()() const
{
  return count_;
}
