#ifndef SUBSEQ_LEN_COUNTER_H
#define SUBSEQ_LEN_COUNTER_H

namespace zaitsev
{
  class SubsequenceLengthCounter
  {
  public:
    SubsequenceLengthCounter();
    void operator()(long long);
    unsigned long long operator()() const;
  private:
    long long beg_element_;
    unsigned long long curr_len_;
    unsigned long long max_len_;
    void reset(long long);
  };
}
#endif
