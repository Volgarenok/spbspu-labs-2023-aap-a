#ifndef MONDEC_H
#define MONDEC_H
#include <cstddef>

namespace strelyaev
{
  class Mondec
  {
    public:
      Mondec();
      void operator()(int num);
      size_t resultLog() const;
      void operator()();
    private:
      size_t new_counter;
      size_t max_counter;
      int past_number;
  };
}
#endif
