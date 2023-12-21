#include "incseq.hpp"
#include <limits>
#include <stdexcept>

skopchenko::IncSeq::IncSeq():
  prevNum_(0),
  count_(0)
{}

void skopchenko::IncSeq::operator()(int current)
{
  if (prevNum_ == 0)
  {
    prevNum_ = current;
  }
  else if (current > prevNum_)
  {
    size_t max_count = std::numeric_limits< size_t >::max();
    if (count_ == max_count)
    {
      throw std::logic_error("maximum sequence lenght exceeded");
    }
    else
    {
      count_++;
    }
  }
  prevNum_ = current;
}

size_t skopchenko::IncSeq::operator()() const
{
  return count_;
}
