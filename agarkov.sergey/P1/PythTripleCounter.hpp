#ifndef PYTHTRIPLECOUNTER_HPP
#define PYTHTRIPLECOUNTER_HPP

#include <cstddef>

namespace agarkov
{
  struct PythTripleCounter
  {
  public:
    PythTripleCounter();
    void operator()(int cur);
    int getCount() const;
  private:
    size_t count;
    int second;
    int third;
  };
}

#endif
