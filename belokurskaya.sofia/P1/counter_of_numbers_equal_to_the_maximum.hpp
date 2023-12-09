#ifndef COUNTER_OF_NUMBERS_EQUAL_TO_THE_MAXIMUM_HPP
#define COUNTER_OF_NUMBERS_EQUAL_TO_THE_MAXIMUM_HPP

#include <cstddef>
#include <limits>

namespace belokurskaya
{
  struct CounterOfNumbersEqualToTheMaximum
  {
    CounterOfNumbersEqualToTheMaximum();

    void operator()(int number);
    size_t operator()() const;

  private:

    int max_element_;
    size_t max_element_amount_;
  };
}
#endif
