#include <limits>
#include <stdexcept>
#include "EVEN_COUNTER.hpp"

isaychev::even_counter::even_counter():
  count(0),
  max_count(0)
{}

void isaychev::even_counter::evn_cnt(int num)
{
  unsigned long long int u_border = std::numeric_limits <unsigned long long int>::max();
  if (count == u_border)
  {
    throw std::logic_error("sequence is too long");
  }
  else if (num % 2 == 0)
  {
    ++count;
    if (count > max_count)
    {
      max_count = count;
    }
  }
  else if (num % 2 != 0)
  {
    count = 0;
  }
}

unsigned long long int isaychev::even_counter::get_res() const
{
  return max_count;
}
