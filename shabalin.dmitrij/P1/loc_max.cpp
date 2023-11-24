#include "loc_max.hpp"
#include <limits>
#include <stdexcept>

shabalin::LocMax::LocMax():
  firstNumber_(0),
  secondNumber_(0),
  count_(0)
{}

void shabalin::LocMax::operator()(long long Number)
{
  if (firstNumber_ == 0)
  {
    firstNumber_ = Number;
    if (firstNumber_ == 0)
    {
      throw std::logic_error("Is not a sequence");
    }
  }
  else if (secondNumber_ == 0)
  {
    secondNumber_ = Number;
  }

  size_t max_size = std::numeric_limits< size_t >::max();

  if (secondNumber_ > Number && secondNumber_ > firstNumber_)
  {
    if (count_ == max_size)
    {
      throw std::logic_error("Sequence is too long");
    }
    ++count_;   
  }
  firstNumber_ = secondNumber_;
  secondNumber_ = Number;
}

size_t shabalin::LocMax::operator()() const
{
  return count_;
}
