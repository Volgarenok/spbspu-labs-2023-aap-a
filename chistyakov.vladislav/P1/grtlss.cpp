#include "grtlss.hpp"
#include <limits>
#include <stdexcept>

chistyakov::GrtLss::GrtLss():
  firstNumber_(0),
  middleNumber_(0),
  counter_(0),
  isSecuenceOk_(false)
{}

void chistyakov::GrtLss::operator()(int number)
{
  if (!firstNumber_)
  {
    firstNumber_ = number;
  }
  else if (!middleNumber_)
  {
    middleNumber_ = number;
  }
  else
  {
    if (!isSecuenceOk_)
    {
      isSecuenceOk_ = true;
    }

    if (firstNumber_ > middleNumber_ && middleNumber_ > number)
    {
      size_t max_size = std::numeric_limits< size_t >::max();
      if (counter_ == max_size)
      {
        throw std::logic_error("sequence is too long");
      }
      else
      {
        ++counter_;
      }
    }
    firstNumber_ = middleNumber_;
    middleNumber_ = number;
  }
}

size_t chistyakov::GrtLss::operator()() const
{
  if (!isSecuenceOk_)
  {
    throw std::invalid_argument("sequence is too short");
  }
  else
  {
    return counter_;
  }
}
