#include "submax_checker.hpp"
#include <limits>
#include <stdexcept>

nikitov::SubmaxChecker::SubmaxChecker():
  actualMax_(std::numeric_limits< long long int >::min()),
  prevMax_(std::numeric_limits< long long int >::min())
{}

void nikitov::SubmaxChecker::operator()(long long int number)
{
  if (number >= actualMax_)
  {
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
  if (prevMax_ == std::numeric_limits< long long int >::min())
  {
    throw std::logic_error("This sequence is too short");
  }
  return prevMax_;
}
