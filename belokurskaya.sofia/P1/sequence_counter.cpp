#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

const int Min = std::numeric_limits<int>::min();

belokurskaya::SequenceCounter::SequenceCounter():
  count_(0),
  max_(Min),
  count_max_(1)
{}

void belokurskaya::SequenceCounter::operator()(int number)
{
  size_t max_size = std::numeric_limits<size_t>::max();
  if (count_ == max_size)
  {
      throw std::logic_error("sequence is too long");
  }
  if (number > max_)
  {
    max_ = number;
    count_max_ = 1;
  }
  else if (number == max_)
  {
    ++count_max_;
  }
  ++count_;
}
size_t belokurskaya::SequenceCounter::operator()() const
{
  return count_max_;
}
