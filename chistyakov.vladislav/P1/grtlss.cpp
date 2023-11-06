#include "grtlss.hpp"
#include <limits>
#include <stdexcept>

chistyakov::GrtLss::GrtLss() :
    fstNum_(0),
    midNum_(0),
    counter_(0),
    isSecuence_(false)
{}

void chistyakov::GrtLss::countGrt(intmax_t number)
{
  if (!fstNum_)
  {
    fstNum_ = number;
  }
  else if (!midNum_)
  {
    midNum_ = number;
  }
  else
  {
    if (!isSecuence_)
    {
      isSecuence_ = true;
    }

    size_t max_size = std::numeric_limits< size_t >::max();
    if (counter_ > max_size)
    {
      throw std::logic_error("sequence is too long");
    }

    if (fstNum_ > midNum_ and midNum_ > number)
    {
      ++counter_;
    }
    fstNum_ = midNum_;
    midNum_ = number;
  }
}

bool chistyakov::GrtLss::isSecuenceOk() const
{
  return isSecuence_;
}

size_t chistyakov::GrtLss::getResultGrt() const
{
  return counter_;
}
