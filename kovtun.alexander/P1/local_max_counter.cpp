#include "local_max_counter.hpp"


kovtun::LocalMaxCounter::LocalMaxCounter():
  counter_(0),
  firstNumber_(0),
  secondNumber_(0),
  thirdNumber_(0)
{}

void kovtun::LocalMaxCounter::operator()(int number)
{
  if (firstNumber_ == 0)
  {
    firstNumber_ = number;
    return;
  }

  if (secondNumber_ == 0)
  {
    secondNumber_ = number;
    return;
  }

  thirdNumber_ = number;
  if (firstNumber_ < secondNumber_ && secondNumber_ > thirdNumber_)
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (counter_ == max_size)
    {
      throw std::overflow_error("LocalMaxCounter overflow");
    }
    counter_++;
  }

  firstNumber_ = secondNumber_;
  secondNumber_ = thirdNumber_;
}

size_t kovtun::LocalMaxCounter::operator()() const
{
  if (firstNumber_ == 0)
  {
    throw std::out_of_range("LocalMaxCounter hasn't counted anything");
  }

  return counter_;
}
