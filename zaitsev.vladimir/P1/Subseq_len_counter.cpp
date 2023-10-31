#include "Subseq_len_counter.h"
#include <algorithm>
#include <limits>
#include <stdexcept>

zaitsev::SubsequenceLengthCounter::SubsequenceLengthCounter():
  beg_element_(0),
  curr_len_(0),
  max_len_(0)
{}

unsigned long long zaitsev::SubsequenceLengthCounter::operator()() const
{
  return std::max(max_len_, curr_len_);
}

void zaitsev::SubsequenceLengthCounter::reset(long long beg_element)
{
  beg_element_ = beg_element;
  curr_len_ = 1;
  max_len_ = max_len_;
}

void zaitsev::SubsequenceLengthCounter::operator()(long long next_element)
{
  if (next_element == beg_element_)
  {
    if (curr_len_ == std::numeric_limits< unsigned long long >::max())
    {
      throw std::overflow_error("Length of subsequence is too long to put it in the unsigned long long type");
    }
    else
    {
      ++curr_len_;
    }
  }
  else
  {
    reset(next_element);
  }
}
