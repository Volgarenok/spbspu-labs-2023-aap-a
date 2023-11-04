#include "mondec.hpp"
#include <limits>
#include <stdexcept>

piyavkin::MonDec::MonDec():
  cur_count_(0),
  max_count_(0),
  prev_(0)
{}
void piyavkin::MonDec::operator()(long long int num)
{
  if (cur_count_ > max_count_)
  {
    max_count_ = cur_count_;
  }
  if (num <= prev_)
  {
    if (1 + cur_count_ == 0)
    {
      throw std::logic_error("error: sequence is too long");
    }
    ++cur_count_;
  }
  else
  {
    cur_count_ = 1;
  }
  prev_ = num;
}
size_t piyavkin::MonDec::operator()() const
{
  return max_count_;
}
