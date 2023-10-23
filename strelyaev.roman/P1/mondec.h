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
      void operator()();
      size_t resultLog() const;

    private:
      size_t max_counter;
      size_t new_counter;
      int past_number;
  };
}
#endif
