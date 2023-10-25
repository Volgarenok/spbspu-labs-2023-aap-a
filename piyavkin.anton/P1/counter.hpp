#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <iostream>
namespace piyavkin
{
  struct MonDec{
    MonDec();
    void operator()(long long int num);
    size_t operator()() const;
  private:
    size_t count_;
    size_t maxc;
    long long int prev;
  };
}
#endif
