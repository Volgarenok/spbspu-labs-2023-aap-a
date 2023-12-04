#ifndef COMPOSITION_HPP
#define COMPOSITION_HPP

#include "sequence_counter.hpp"
#include "first_second_sum.hpp"
#include "more_less_check.hpp"

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
