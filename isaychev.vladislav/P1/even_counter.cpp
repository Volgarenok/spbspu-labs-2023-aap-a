#include <limits>
#include <stdexcept>
#include "EVEN_COUNTER.hpp"

isaychev::Even_counter::Even_counter():
  count(0),
  max_count(0)
{}

void isaychev::Even_counter::operator()(int c_num)
{
  unsigned long long int u_border = std::numeric_limits <unsigned long long int>::max();
  if (count == u_border)
  {
    throw std::logic_error("sequence is too long");
  }
  else if (c_num % 2 == 0)
  {
    ++count;
    if (count > max_count)
    {
      max_count = count;
    }
  }
  else if (c_num % 2 != 0)
  {
    count = 0;
  }
}

unsigned long long int isaychev::Even_counter::operator()() const
{
  return max_count;
}
