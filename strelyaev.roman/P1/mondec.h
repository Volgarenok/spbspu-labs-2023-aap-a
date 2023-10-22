#ifndef MONDEC_H
#define MONDEC_H
#include <cstddef>
class Mondec
{
  public:
    Mondec();
    void limitCheck(int num);
    size_t resultlog() const;
  private:
    size_t counter;
};
#endif
