#include "PythTripleCounter.hpp"

#include <stdexcept>
#include <limits>
#include <cstddef>

namespace agarkov
{
  bool isPithTriple(int a, int b, int c)
  {
    return ((a * a) == (b * b) + (c * c)) && (b > 0) && (c > 0);
  }

  bool isPithTripleInAnyComb(int a, int b, int c)
  {
    return isPithTriple(a, b ,c) || isPithTriple(b, c ,a) || isPithTriple(c, a, b);
  }
}
agarkov::PythTripleCounter::PythTripleCounter():
  count(0),
  second(0),
  third(0)
{}

void agarkov::PythTripleCounter::operator()(int num)
{
  if (isPithTripleInAnyComb(num, second, third))
  {
    if (count == std::numeric_limits< size_t >::max())
    {
      throw std::logic_error("The upper limit size_t");
    }
    count++;
  }
  third = second;
  second = num;
}

int agarkov::PythTripleCounter::getCount() const
{
  return count;
}
