#include <iostream>
#include <limits>
#include <stdexcept>
#include "frist_second_sum.hpp"

vyzhanov1::Sum::Sum(): count_all(0), count(0), first(0), second(0), third(0)
{}

void vyzhanov1::Sum::operator()(int num)
{
  third = second;
  second = first;
  first = num;
  size_t max_s = std::numeric_limits< size_t >::max();
  if((second > 0 && third > std::numeric_limits<int>::max() - second) || (second < 0 && third < std::numeric_limits<int>::min() - second))
  {
    throw std::logic_error("Overflow!\n");
  }
  if (count_all == max_s)
  {
    throw std::logic_error("Sequence is too long!\n");
  }
  if (num == 0)
  {
    if(count_all <= 2 )
    {
      throw std::logic_error("Sequence is too short!\n");
    }
  }
  else if(count_all < max_s)
  {
    if (first == second+third)
    {
      ++count;
    }
  }
  ++count_all;
}
size_t vyzhanov1::Sum::operator()() const
{
  return count;
}
