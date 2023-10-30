#include <iostream>
#include "sequenceofnums.hpp"
#include <limits>

arakelyan::SequenceOfNums::SequenceOfNums():
  count_(0),
  length_(1)
{}

void arakelyan::SequenceOfNums::counter(int curr,int past)
{
  ++length_;
  size_t max_length = std::numeric_limits< size_t >::max();
  if (length_ == max_length)
  {
    throw std::logic_error("Sequense is too long");
  } else if ((length_ == 2 && curr == 0) || (curr == 0 && length_ == 1))
  {
    throw std::logic_error("Sequence is too short");
  }
  if (curr % past == 0 && curr != 0)
  {
    ++count_;
  }
};

size_t arakelyan::SequenceOfNums::get_count() const
{
  return count_;
}
