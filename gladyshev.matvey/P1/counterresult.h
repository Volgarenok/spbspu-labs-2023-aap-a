#ifndef COUNTERRESULT_H
#define COUNTERRESULT_H

namespace gladyshev
{
  struct Counterreversal
  {
    Counterreversal();
    void operator()(long long int number);
    unsigned long long int operator()() const;
    unsigned long long counterznak;
    long long int number;
    long long int supnumber;
    unsigned long long counter;
  };
}
#endif
