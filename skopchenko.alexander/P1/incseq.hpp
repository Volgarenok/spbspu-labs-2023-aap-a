#ifndef INCSEQ_HPP
#define INCSEQ_HPP

#include <cstddef>

namespace skopchenko
{
  struct IncSeq
  {
  public:
    IncSeq();
    void operator()(int current);
    size_t operator()() const;

  private:
    int prevNum_;
    size_t count_;
  };
}

#endif
