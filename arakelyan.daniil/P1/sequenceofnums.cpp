#include <iostream>
#include "sequenceofnums.hpp"
#include <limits>

arakelyan::SequenceOfNums::SequenceOfNums():
  count(0)
{}

bool arakelyan::SequenceOfNums::lengthCheck(size_t length, int curr) {
  size_t max_length = std::numeric_limits<size_t>::max();
  if (length == max_length) {
    throw std::logic_error("Sequense is too long\n");
  } else if ((length == 2 && curr == 0) || (curr == 0 && length == 1)) {
    throw std::logic_error("Sequence is too short\n");
  } else {
    return 0;
  }
};

void arakelyan::SequenceOfNums::countOfque(int a, int b) {
  if (a % b == 0) {
    ++count;
  }
};

size_t arakelyan::SequenceOfNums::get_count() {
  return count;
};
