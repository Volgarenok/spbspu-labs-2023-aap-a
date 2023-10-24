#ifndef LOCAL_MIN_COUNTER_HPP
#define LOCAL_MIN_COUNTER_HPP

#include <cstddef>
namespace namestnikov
{
  struct LocalMinCounter
  {
    LocalMinCounter();
    void count(int lastnumber, int currentnumber, int futurenumber);
    size_t get_result() const;
  private:
    size_t count_;
  };
}
#endif
