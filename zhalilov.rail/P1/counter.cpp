#include "counter.hpp"

zhalilov::Counter::Counter():
  count(1),
  maxSeq(0)
{}

void zhalilov::Counter::operator()(int prev, int curr)
{
  if(curr == prev)
  {
    count++;
  }
  else
  {
    count = 1;
  }

  if(count > maxSeq)
  {
    maxSeq = count;
  }
}

size_t zhalilov::Counter::operator()() const
{
  return maxSeq;
}
