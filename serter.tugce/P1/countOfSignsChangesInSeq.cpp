#include "countOfSignsChangesInSeq.hpp"
#include <cstddef>

serter::CountOfSignsChangesInSeq::CountOfSignsChangesInSeq():
  currentNumber_(0),
  count_(0)
{}

void serter::CountOfSignsChangesInSeq::operator()(int number)
{
   if (currentNumber_ >= 0 && number < 0)
   {
     ++count_;
   }
   else if (currentNumber_ <= 0 && number > 0)
   {
     ++count_;
   }
   currentNumber_ = number;
}

size_t serter::CountOfSignsChangesInSeq::operator()() const
{
  return count_;
}
