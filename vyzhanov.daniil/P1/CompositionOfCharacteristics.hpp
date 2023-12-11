#ifndef COMPOSITIONOFCHARACTERISTICS_HPP
#define COMPOSITIONOFCHARACTERISTICS_HPP

#include "CountAfterMax.hpp"
#include "CountEqualSumTwoPrev.hpp"
#include "PrevMoreNextLessCheck.hpp"

namespace vyzhanov
{
  struct SequenceSpec
  {
    void operator()(int num);
    size_t getCount() const;
    size_t getSum() const;
    size_t checkMoreLess() const;
    private:
      CountAfterMax count;
      CountEqualSumTwoPrev sum;
      MoreAndLess moreless;
   };
}
#endif
