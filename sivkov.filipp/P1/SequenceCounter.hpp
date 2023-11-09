#ifndef SEQUENCECOUNTER_HPP
#define SEQUENCECOUNTER_HPP
#include <cstddef>
namespace sivkov
{
  struct SequenceCounter
  {
    SequenceCounter();
  public:
    void operator()(int num);
    size_t operator()() const;
  private:
    int num_old_;
    int num_;
    size_t k_;
  };
}
#endif

