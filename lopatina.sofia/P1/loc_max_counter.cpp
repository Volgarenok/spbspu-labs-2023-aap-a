#include "loc_max_counter.hpp"
#include <limits>
#include <stdexcept>

lopatina::Loc_Max_Counter::Loc_Max_Counter():
  count_(0)
{}

void lopatina::Loc_Max_Counter::operator()(int) {
  size_t max_size = std::numeric_limits< size_t >::max();
  if (count_ == max_size) {
    throw std::logic_error("Sequence is too long");
  }
  count_ += 1;
}
size_t lopatina::Loc_Max_Counter::operator()() const {
  return count_;
}
