#ifndef GRTLSS_HPP
#define GRTLSS_HPP

#include <cstddef>

namespace chistyakov
{
  struct GrtLss
  {
  public:
    GrtLss();
    void countGrt(int number);
    bool isSecuenceOk() const;
    size_t getResultGrt() const;

  private:
    int fstNum_;
    int midNum_;
    size_t counter_;
    bool isSecuence_;
  };
}
#endif
