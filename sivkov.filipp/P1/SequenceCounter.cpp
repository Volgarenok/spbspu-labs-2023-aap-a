#include "SequenceCounter.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

<<<<<<< Updated upstream
sivkov::SequenceCounter::SequenceCounter():
=======
sivkov::CountIfDivideWithoutRemaining::CountIfDivideWithoutRemaining():
>>>>>>> Stashed changes
  k_(0),
  num_(0),
  num_old_(0)
{}

<<<<<<< Updated upstream
void sivkov::SequenceCounter::operator()(int num)
=======
void sivkov::CountIfDivideWithoutRemaining::operator()(int num)
>>>>>>> Stashed changes
{
  num_ = num;
  size_t max_size = std::numeric_limits< size_t >::max();

  if (num_ != 0)
  {
    if ((num_old_ != 0) && (num_old_ % num_ == 0))
    {
      ++k_;
    }
    num_old_ = num;
    if (k_ == max_size)
    {
      throw std::logic_error("Sequence is to long...");
    }
  }
}
<<<<<<< Updated upstream
size_t sivkov::SequenceCounter::operator()() const
=======
size_t sivkov::CountIfDivideWithoutRemaining::operator()() const
>>>>>>> Stashed changes
{
  return k_;
}
