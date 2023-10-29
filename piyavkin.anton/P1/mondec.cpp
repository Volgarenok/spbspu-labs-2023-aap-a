#include "mondec.hpp"
#include <limits>
#include <stdexcept>

piyavkin::MonDec::MonDec():
 cur_count(0),
 max_count(0),
 prev(std::numeric_limits< long long int >::max())
{}
void piyavkin::MonDec::operator()(long long int num)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (cur_count == max_size)
  {
    throw std::logic_error("error\n");
  }
  else if (num == 0)
  {
    if (cur_count > max_count)
    {
      max_count = cur_count;
    }
  }
  else if (num <= prev)
  {
    ++cur_count;
  }
  else
  {
    if (cur_count > max_count)
    {
      max_count = cur_count;
    }
    cur_count = 1;
  }
  prev = num;
}
size_t piyavkin::MonDec::operator()() const
{
  return max_count;
}
