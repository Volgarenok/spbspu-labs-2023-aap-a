#ifndef LOC_MAX_COUNTER_HPP
#define LOC_MAX_COUNTER_HPP

#include <cstddef>
struct Loc_Max_Counter {
  Loc_Max_Counter();
  void count(int num);
  size_t get_result() const;
private:
  int number_1;
  int number_2;
  int number_3;
  unsigned int flag;
  size_t count_;
};

#endif
