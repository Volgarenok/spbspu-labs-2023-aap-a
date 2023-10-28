#ifndef SEQ_HPP
#define SEQ_HPP
#include <iostream>
namespace sivkov
{
  struct SeqCount
  {
    SeqCount();
    void operator()(int num, int num_old);
    size_t operator()() const;
  private:
    size_t k1;
  };
}

#endif

