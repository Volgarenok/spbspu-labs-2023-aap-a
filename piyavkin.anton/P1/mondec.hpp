#ifndef MONDEC_HPP
#define MONDEC_HPP

#include <cstddef>
namespace piyavkin
{
  struct MonDec
  {
    MonDec();
    void operator()(long long int num);
    size_t operator()() const;
  private:
    size_t cur_count_;
    size_t max_count_;
    long long int prev_;
  };
}
#endif
