#include "sign_change_counter.hpp"


kovtun::SignChangeCounter::SignChangeCounter():
  counter_(0),
  previousNumber_(0)
{}

void kovtun::SignChangeCounter::operator()(int number)
{
  if (previousNumber_ == 0)
  {
    previousNumber_ = number;
    return;
  }

  if ((previousNumber_ > 0 && number < 0) || (previousNumber_ < 0 && number > 0))
  {
    counter_++;
  }

  previousNumber_ = number;
}

size_t kovtun::SignChangeCounter::operator()()
{
  return counter_;
}
