#ifndef SEQUENCEOFNUMS_HPP
#define SEQUENCEOFNUMS_HPP
#include <cstddef>
namespace arakelyan
{
  struct SequenceOfNums
  {
    SequenceOfNums();
  private:
    size_t count;
  public:
    bool lengthCheck (size_t length,int curr);
    void countOfque (int a,int b);
    size_t get_count ();
  };
}
#endif
