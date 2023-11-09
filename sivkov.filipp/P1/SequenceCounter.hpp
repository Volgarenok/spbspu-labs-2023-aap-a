#ifndef SEQUENCECOUNTER_HPP
#define SEQUENCECOUNTER_HPP
#include <cstddef>
namespace sivkov
{
  struct SequenceCount
  {
    SequenceCount();
  public:
    void operator()(int num, int num_old);
    size_t operator()() const;
  private:
    size_t k_;
  };
}
#endif

