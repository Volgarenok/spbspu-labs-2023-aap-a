#include "loc_max.hpp"
#include <limits>
#include <stdexcept>

shabalin::LocMax::LocMax(signed long long firstInt,signed long long secondInt,signed long long thirdInt):
  firstNumber(firstInt),
  secondNumber(secondInt),
  thirdNumber(thirdInt),
  count_(0)
{}

void shabalin::LocMax::operator()(signed long long Number)
{
  thirdNumber = Number;
  size_t max_size = std::numeric_limits< size_t >::max();
  if (count_ == max_size)
  {
    throw std::logic_error("Sequence is too long\n");
  }
  if (secondNumber > thirdNumber && secondNumber > firstNumber)
  {
    ++count_;
  }
  firstNumber = secondNumber;
  secondNumber = thirdNumber;
}

size_t shabalin::LocMax::operator()() const
{
  return count_;
};
