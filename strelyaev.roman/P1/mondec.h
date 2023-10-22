#ifndef MONDEC_H
#define MONDEC_H
#include <cstddef>
class Mondec
{
  public:
    Mondec();
    void numberCheck(int num);
    size_t resultlog() const;
    void counterCheck();
  private:
    size_t new_counter;
    size_t max_counter;
    int past_number;
};
#endif
