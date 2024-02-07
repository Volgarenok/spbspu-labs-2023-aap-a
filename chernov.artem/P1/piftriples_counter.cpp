#include "piftriples_counter.hpp"
#include <stdexcept>
#include <limits>

chernov::PifTriplesCounter::PifTriplesCounter():
  piftriples_(0),
  first_el_(0),
  second_el_(0)
{}

void chernov::PifTriplesCounter::operator()(int number)
{
  if (findPifTriples(number) == 1 && first_el_ != 0 && second_el_ != 0)
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (piftriples_ == max_size)
    {
      throw std::logic_error("Sequence is too long");
    }
    ++piftriples_;
  }
  first_el_ = second_el_;
  second_el_ = number;
}

bool chernov::PifTriplesCounter::findPifTriples(int number)
{
  int a = first_el_;
  int b = second_el_;
  int c = number;
  return (c * c == (a * a + b * b));
}

size_t chernov::PifTriplesCounter::operator()() const
{
  return piftriples_;
}
