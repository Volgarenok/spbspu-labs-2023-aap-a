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
    size_t k_;
    int num_;
    int num_old_;
  };
}
#endif

