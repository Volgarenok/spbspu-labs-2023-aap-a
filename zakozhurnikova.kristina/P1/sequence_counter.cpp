#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

zakozhurnikova::SequenceAfterMaximum::SequenceAfterMaximum():
  count_(0),
  max_(std::numeric_limits< int >::min())
{}
void zakozhurnikova::SequenceAfterMaximum::operator()(int number)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (number <= max_)
  {
    if (count_ == max_size)
    {
      throw std::logic_error("sequence is too long");
    }
    ++count_;
  }
  else
  {
    count_ = 0;
    max_ = number;
  }
}
size_t zakozhurnikova::SequenceAfterMaximum::operator()() const
{
  return count_;
}
