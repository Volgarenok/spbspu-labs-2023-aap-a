#ifndef MONDEC_HPP
#define MONDEC_HPP

#include <cstddef>
namespace piyavkin
{
  struct MonDec{
    MonDec();
    void operator()(long long int num);
    size_t operator()() const;
  private:
    size_t cur_count;
    bool flag;
    size_t max_count;
    long long int prev;
  };
}
#endif
