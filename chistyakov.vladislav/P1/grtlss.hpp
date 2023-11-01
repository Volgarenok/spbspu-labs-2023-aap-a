#ifndef GRTLSS_HPP
#define GRTLSS_HPP

#include <cstddef>
#include <cstdint>

namespace chistyakovGrtLss
{
  struct GrtLss
  {
  public:
    GrtLss();
    void countGrt(intmax_t number);
    bool isSecuenceOk() const;
    size_t getResultGrt() const;

  private:
    intmax_t fstNum_;
    intmax_t midNum_;
    size_t counter_;
    bool isSecuence_;
  };
}
#endif
