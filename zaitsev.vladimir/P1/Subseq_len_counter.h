#ifndef SUBSEQ_LEN_COUNER_H
#define SUBSEQ_LEN_COUNER_H

namespace zaitsev
{
  class Subseq_len_counter
  {
  public:
    Subseq_len_counter();
    void operator()(long long);
    void reset(long long);
    unsigned long long get_len();
  private:
    long long seq_beg_element;
    unsigned long long curr_seq_len;
  };
}
#endif  