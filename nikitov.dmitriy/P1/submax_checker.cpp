#include "submax_checker.hpp"
#include <limits>
#include <stdexcept>

nikitov::SubmaxChecker::SubmaxChecker():
  actualMax_(std::numeric_limits< long long int >::min()),
  prevMax_(std::numeric_limits< long long int >::min()),
  count_(0)
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
  if (count_ == std::numeric_limits< size_t >::max())
  {
    throw std::logic_error("This sequence is too long");
  }
  ++count_;
}
long long int nikitov::SubmaxChecker::operator()() const
{
  if (count_ < 2)
  {
    throw std::logic_error("This sequence is too short");
  }
  return prevMax_;
}
