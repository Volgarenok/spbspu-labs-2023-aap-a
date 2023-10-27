#ifndef SUBSEQ_LEN_COUNTER_H
#define SUBSEQ_LEN_COUNTER_H

namespace zaitsev
{
  class Subseq_len_counter
  {
  public:
    Subseq_len_counter();
    void operator()(long long);
    void reset(long long);
    unsigned long long get_max_len() const;
  private:
    long long beg_element_;
    unsigned long long curr_len_;
    unsigned long long max_len_;
  };
}
#endif
