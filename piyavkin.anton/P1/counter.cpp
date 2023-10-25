#include "counter.hpp"
#include <limits>
#include <stdexcept>

piyavkin::MonDec::MonDec():
    count_(0),
    maxc(0),
    prev(std::numeric_limits< long long int >::max())
  {}
void piyavkin::MonDec::operator()(long long int num) {
  size_t max_size = std::numeric_limits< size_t >::max();
  if (count_ == max_size) {
    throw std::logic_error("error\n");
  }
  else if (num == 0) {
    if (count_ > maxc) {
      maxc = count_;
    }
  }
  else if (num <= prev) {
    ++count_;
  }
  else {
    if (count_ > maxc) {
      maxc = count_;
    }
    count_ = 1;
  }
  prev = num;
}
size_t piyavkin::MonDec::operator()() const {
  return maxc;
}
