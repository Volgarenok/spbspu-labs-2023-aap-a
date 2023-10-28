#ifndef SEQ_HPP
#define SEQ_HPP
#include <iostream>
namespace sivkov
{
  struct SeqCount
  {
    SeqCount();
    void k(int num, int num_old);
    size_t get_result() const;
  private:
    size_t k1;
  };
}

#endif

