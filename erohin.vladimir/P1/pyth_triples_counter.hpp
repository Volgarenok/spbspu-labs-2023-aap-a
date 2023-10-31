#ifndef PYTH_TRIPLES_HPP
#define PYTH_TRIPLES_HPP

#include <cstddef>
namespace erohin
{
  struct PythTriplesCounter
  {
    PythTriplesCounter();
    void operator()(int current);
    size_t operator()() const;
  private:
    size_t pythtriples_;
    int prev_;
    int pre_prev_;
    bool isPythTriple(int current);
  };
}

#endif
