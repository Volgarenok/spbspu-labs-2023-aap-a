#ifndef COUNTERREVERSAL_H
#define COUNTERREVERSAL_H

#include <cstddef>

namespace gladyshev
{
  struct CounterReversal
  {
    CounterReversal();
    void operator()(long long int number_);
    size_t operator()() const;
  private:
    size_t counter_sign_;
    long long int number_;
    long long int sup_number_;
  };
}
#endif
