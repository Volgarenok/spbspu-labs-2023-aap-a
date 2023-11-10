#include "submax_checker.hpp"
#include <limits>
#include <stdexcept>

nikitov::SubmaxChecker::SubmaxChecker():
  actualMax_(std::numeric_limits< long long int >::min()),
  prevMax_(std::numeric_limits< long long int >::min()),
  status_(0)
{}

void nikitov::SubmaxChecker::operator()(long long int number)
{
  if (status_ == 1)
  {
    status_ = 2;
  }
  if (number >= actualMax_)
  {
    if (status_ != 2)
    {
      status_ = 1;
    }
    prevMax_ = actualMax_;
    actualMax_ = number;
  }
  else if (number > prevMax_)
  {
    prevMax_ = number;
  }
}
long long int nikitov::SubmaxChecker::operator()() const
{
  if (status_ != 2)
  {
    throw std::logic_error("This sequence is too short");
  }
  return prevMax_;
}
