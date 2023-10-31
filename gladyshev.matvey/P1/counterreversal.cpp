#include "counterreversal.h"

#include <iostream>
#include <limits>
#include <stdexcept>


gladyshev::CounterReversal::CounterReversal():
   counterznak(0),
   number(0),
   supnumber(0)
{}

void gladyshev::CounterReversal::operator()(long long int number)
{
  size_t maxsize = std::numeric_limits< size_t >::max();
  if (((supnumber > 0) && (number < 0)) || ((supnumber < 0) && (number > 0)))
  {
    ++counterznak;
  }
  if (counterznak == maxsize)
  {
    throw std::logic_error("sequence is too long");
  }
  supnumber = number;
}
unsigned long long int gladyshev::CounterReversal::operator()() const
{
  return counterznak;
}

