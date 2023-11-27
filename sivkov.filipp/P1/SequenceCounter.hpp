#ifndef SEQUENCECOUNTER_HPP
#define SEQUENCECOUNTER_HPP
#include <cstddef>
namespace sivkov
{
<<<<<<< Updated upstream
  struct SequenceCounter
  {
    SequenceCounter();
=======
  struct CountIfDivideWithoutRemaining
  {
    CountIfDivideWithoutRemaining();
>>>>>>> Stashed changes
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

