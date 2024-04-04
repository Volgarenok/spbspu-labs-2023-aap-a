#include "loc_max_counter.hpp"
#include <limits>
#include <stdexcept>

prisyach::LocMaxCounter::LocMaxCounter():
  number1_(0),
  number2_(0),
  number3_(0),
  flag_(0),
  count_(0)
{}

void prisyach::LocMaxCounter::operator()(int num)
{
  if (number1_ == 0) {
    number1_ = num;
  } else if (number2_ == 0) {
    number2_ = num;
  } else {
    number3_ = num;
    flag_ = 1;
  }

  if (number2_ >= number1_ && number2_ >= number3_ && number3_ != 0 && flag_ == 1) {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (count_ == max_size) {
      throw std::logic_error("Sequence is too long");
    }
    count_ += 1;
  }
  if (flag_ == 1) {
    number1_ = number2_;
    number2_ = number3_;
  }
}

size_t prisyach::LocMaxCounter::operator()() const
{
  if (number3_ == 0) {
    throw std::logic_error("Sequence is too short\n");
  }
  return count_;

}
