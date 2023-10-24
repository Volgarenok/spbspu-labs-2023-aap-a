#include "sequence.hpp"
#include <limits>
#include <stdexcept>
#include <iostream>

marishin::Sequence::Sequence():
  global_count(0),
  prev1(0),
  prev2(0),
  count(0)
{}

