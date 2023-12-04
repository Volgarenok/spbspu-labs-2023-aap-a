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
    counter_++;
  }

  firstNumber_ = secondNumber_;
  secondNumber_ = thirdNumber_;
}

const size_t kovtun::LocalMaxCounter::operator()()
{
  return counter_;
}
