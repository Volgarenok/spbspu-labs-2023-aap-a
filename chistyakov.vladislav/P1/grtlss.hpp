#ifndef GRTLSS_HPP
#define GRTLSS_HPP

#include <cstddef>

namespace chistyakov
{
  struct GrtLss
  {
  public:
    GrtLss();
    void operator()(int number);
    size_t operator()() const;

  private:
    int fstNum_;
    int midNum_;
    size_t counter_;
    bool isSecuence_;
  };
}
#endif
