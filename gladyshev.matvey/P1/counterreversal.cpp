#include "counterreversal.h"

#include <limits>
#include <stdexcept>

gladyshev::CounterReversal::CounterReversal():
  counter_sign_(0),
  number_(0),
  sup_number_(0)
{}

void gladyshev::CounterReversal::operator()(long long int number_)
{
  size_t maxsize = std::numeric_limits< size_t >::max();
  if (((sup_number_ > 0) && (number_ < 0)) || ((sup_number_ < 0) && (number_ > 0)))
  {
    if (counter_sign_ == maxsize)
    {
      throw std::logic_error("sequence is too long");
    }
    ++counter_sign_;
  }
  sup_number_ = number_;
}

size_t gladyshev::CounterReversal::operator()() const
{
  return counter_sign_;
}
