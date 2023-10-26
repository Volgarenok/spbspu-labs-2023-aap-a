#include <limits>
#include <stdexcept>
#include "sequencenumofmax.hpp"
#include <iostream>

SequenceNumOfMax::SequenceNumOfMax():
  counter(0)
{}

void SequenceNumOfMax::start_max(size_t nowNum)
{
  maxNum = nowNum;
  counter = 1;
}

void SequenceNumOfMax::count(size_t nowNum)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (counter == max_size)
  {
    throw std::logic_error("sequence is too long\n");
  }
  else if (maxNum == max_size)
  {
    throw std::logic_error("max numder is too big\n");
  }
  else if (nowNum == max_size)
  {
    throw std::logic_error("input numder is too big\n");
  }

  if (nowNum > maxNum)
  {
    maxNum = nowNum;
    counter = 1;
  }
  else if (nowNum == maxNum)
  {
    ++counter;
  }
}

size_t SequenceNumOfMax::get_result() const
{
  return counter;
}

