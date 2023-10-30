#include "local_max_counter.hpp"
#include <limits>
#include <stdexcept>

baranov::LocalMaxCounter::LocalMaxCounter(long long int firstNumber, long long int secondNumber):
  prevNumber(firstNumber),
  currentNumber(secondNumber),
  nextNumber(1),
  count_(0)
{}

void baranov::LocalMaxCounter::operator()(long long int number)
{
  nextNumber = number;
  if (currentNumber > prevNumber && currentNumber > nextNumber)
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (count_ == max_size)
    {
      throw std::logic_error("sequence is too long");
    }
    ++count_;
  }
prevNumber = currentNumber;
currentNumber = nextNumber;
}

size_t baranov::LocalMaxCounter::operator()() const
{
  return count_;
}

