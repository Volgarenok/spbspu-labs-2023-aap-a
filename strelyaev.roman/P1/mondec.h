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
      size_t operator()() const;

    private:
      size_t max_counter_;
      size_t new_counter_;
      int past_number_;
  };
}
#endif
