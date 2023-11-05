#include <iostream>
#include "counterofnums.hpp"
#include <limits>

arakelyan::CounterOfNums::CounterOfNums():
  count_(0),
  length_(0),
  past_num_(0)
{}

void arakelyan::CounterOfNums::operator()(int curr)
{
  length_++;
  size_t max_length = std::numeric_limits< size_t >::max();
  if (length_ == max_length)
  {
    throw std::logic_error("Sequense is too long");
  }
  else if ((length_ == 2 && curr == 0) || (length_ == 1 && curr == 0))
  {
    throw std::logic_error("Sequence is too short");
  }
  if ((curr % past_num_ == 0) && (curr != 0) && (past_num_ != 0))
  {
    ++count_;
  }
  if (curr != 0)
  {
    past_num_ = curr;
  }
}

size_t arakelyan::CounterOfNums::operator()() const
{
  return count_;
}
