#ifndef COUNTERMAIN_H
#define COUNTERMAIN_H

#include <iostream>
namespace gladyshev
{
  struct Countermain
  {
    Countermain();
    void operator()(long long int number);
    unsigned long long int operator()() const;
    unsigned long long counterznak;
    long long int number;
    long long int supnumber;
    unsigned long long counter;
  };
}
#endif
