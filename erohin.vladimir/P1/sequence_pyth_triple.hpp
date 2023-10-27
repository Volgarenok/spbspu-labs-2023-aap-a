#ifndef SEQUENCE_PYTH_HPP
#define SEQUENCE_PYTH_HPP

#include <cstddef>
namespace erohin
{
  struct SequencePythTriple
  {
    SequencePythTriple();
    void operator()(int current);
    size_t operator()() const;
  private:
    size_t number_;
    size_t pythtriple_;
    size_t prev_;
    size_t pre_prev_;
    bool isPythTriple(int current);
  };
}

#endif
