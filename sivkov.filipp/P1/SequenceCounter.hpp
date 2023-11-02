#ifndef SEQUENCECOUNTER_HPP
#define SEQUENCECOUNTER_HPP
#include <cstddef>
namespace sivkov
{
  struct SequenceCount
  {
    SequenceCount();
    void operator()(int num, int num_old);
    size_t operator()() const;
  private:
    size_t k1;
  };
}

#endif

