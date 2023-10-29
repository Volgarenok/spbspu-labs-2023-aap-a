#include "countermain.h"

#include <iostream>
#include <limits>
#include <stdexcept>


gladyshev::Counterreversal::Counterreversal():
    counterznak(0),
    number(0),
    supnumber(0),
    counter(0)
{}

void gladyshev::Counterreversal::operator()(long long int number)
{
  ++counter;
  size_t maxsize = std::numeric_limits< size_t >::max();
  if (counter == maxsize)
  {
    throw std::logic_error("sequence is too long");
  }
  if (number == 0 && counter == 2)
  {
    std::cerr << "sequence is too short\n";
  }
  if (((supnumber > 0) && (number < 0)) || ((supnumber < 0) && (number > 0)))
  {
    ++counterznak;
  }
  supnumber = number;
}
unsigned long long int gladyshev::Counterreversal::operator()() const
{
  return counterznak;
}

