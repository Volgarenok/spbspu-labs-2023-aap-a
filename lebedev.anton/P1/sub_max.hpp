#ifndef SUB_MAX_HPP
#define SUB_MAX_HPP

namespace lebedev
{
  struct SubMaxValue
  {
    SubMaxValue();
    void operator()(int curr_num);
    int operator()() const;
  private:
    int max_;
    int sub_max_;
  };
}
#endif
