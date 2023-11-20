#ifndef COMPOSITION_HPP
#define COMPOSITION_HPP

#include "sequence_counter.hpp"
#include "first_second_sum.hpp"
#include "more_less_check.hpp"
#include <stdexcept>
#include <iostream>

namespace vyzhanov
{
  struct SequenceSpec
  {
    vyzhanov::CountAfterMax counter;
    vyzhanov::SumDup sum;
    vyzhanov::MoreAndLess moreless;

    void operator()(int num)
    {
      return counter(num), sum(num), moreless(num);
    }

    size_t operator()()
    {
      return counter(), sum(), moreless();
    }
  };
}

#endif
