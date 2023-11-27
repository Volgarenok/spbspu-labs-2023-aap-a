#include "loc_max.hpp"
#include <limits>
#include <stdexcept>

shabalin::LocMax::LocMax():
  firstNumber_(0),
  secondNumber_(0),
  count_(0)
{}

void shabalin::LocMax::operator()(long long number)
{
  if (firstNumber_ == 0)
  {
    firstNumber_ = number;
    if (firstNumber_ == 0)
    {
      throw std::logic_error("Is not a sequence");
    }
  }
  else if (secondNumber_ == 0)
  {
    secondNumber_ = number;
  }

  size_t max_size = std::numeric_limits< size_t >::max();

  if (secondNumber_ > number && secondNumber_ > firstNumber_)
  {
    if (count_ == max_size)
    {
      throw std::logic_error("Sequence is too long");
    }
    ++count_;
  }
  firstNumber_ = secondNumber_;
  secondNumber_ = number;
}

size_t shabalin::LocMax::operator()() const
{
  return count_;
}
