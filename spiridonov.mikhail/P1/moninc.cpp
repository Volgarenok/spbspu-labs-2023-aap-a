#include "moninc.hpp"
#include <limits>
#include <stdexcept>

spiridonov::Moninc::Moninc():
  max_length_(0),
  curr_length_(0),
  prev_num_(0)
{}

void spiridonov::Moninc::Moninc::operator()(int num)
{
  const size_t max_size = std::numeric_limits< size_t >::max();
  if (prev_num_ < num)
  {
    if (curr_length_ == max_size)
    {
      throw std::logic_error("The sequence is too long");
    }
    ++curr_length_;
  }
  else
  {
    curr_length_ = 1;
  }
  prev_num_ = num;
  if (curr_length_ > max_length_)
  {
    max_length_ = curr_length_;
  }
}

size_t spiridonov::Moninc::Moninc::operator()() const
{
  return max_length_;
}
