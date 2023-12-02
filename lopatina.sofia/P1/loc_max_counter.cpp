#include "loc_max_counter.hpp"
#include <limits>
#include <stdexcept>

lopatina::Loc_Max_Counter::Loc_Max_Counter():
  number_1(0),
  number_2(0),
  number_3(0),
  flag(0),
  count_(0)
{}

void lopatina::Loc_Max_Counter::operator()(int num)
{
  if (number_1 == 0) {
    number_1 = num;
  } else if (number_2 == 0) {
    number_2 = num;
  } else {
    number_3 = num;
    flag = 1;
  }

  if (number_2 >= number_1 && number_2 >= number_3 && number_3 != 0 && flag == 1) {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (count_ == max_size) {
      throw std::logic_error("Sequence is too long");
    }
    count_ += 1;
  }
  if (flag == 1) {
    number_1 = number_2;
    number_2 = number_3;
  }

size_t lopatina::Loc_Max_Counter::operator()() const
{
  if (number_3 == 0) {
    throw std::logic_error("Sequence is too short\n");
  }
  return count_;
}
