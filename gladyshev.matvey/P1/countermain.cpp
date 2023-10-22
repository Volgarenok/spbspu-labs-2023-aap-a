#include "countermain.h"
#include <limits>
#include <stdexcept>

gladyshev::Countermain::Countermain():
    counterznak(0),
    number(0),
    supnumber(0),
    counter(0)
{}

void gladyshev::Countermain::operator()(long long int number)
{
  ++counter;
  unsigned long long int maxsize = std::numeric_limits< unsigned long long int >::max();
  if (counter == maxsize)
  {
    throw std::logic_error("sequence is too long");
  }
  if (number == 0 && counter == 2)
  {
    std::cerr << "sequence is too short\n";
  }
  if (supnumber * number < 0)
  {
    ++counterznak;
  }
  supnumber = number;
}
unsigned long long int gladyshev::Countermain::operator()() const
{
  return counterznak;
}

