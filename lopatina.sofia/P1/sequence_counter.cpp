#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

lopatina::SequenceCounter::SequenceCounter():
  count_(0)
{}

void lopatina::SequenceCounter::count(int) {
  size_t max_size = std::numeric_limits< size_t >::max();
  if (count_ == max_size) {
    throw std::logic_error("Sequence is too long");
  }
  count_ += 1;
}
size_t lopatina::SequenceCounter::get_result() const {
  return count_;
}
