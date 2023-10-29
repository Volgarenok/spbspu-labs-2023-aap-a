#include "counterresult.h"

#include <iostream>
#include <limits>
#include <stdexcept>


gladyshev::Counterreversal::Counterreversal():
    counterznak(0),
    number(0),
    supnumber(0)
{}

void gladyshev::Counterreversal::operator()(long long int number)
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
unsigned long long int gladyshev::Counterreversal::operator()() const
{
  return counterznak;
}

