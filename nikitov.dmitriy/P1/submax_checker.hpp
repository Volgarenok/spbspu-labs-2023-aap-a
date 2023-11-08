#ifndef SUBMAX_CHECKER_HPP
#define SUBMAX_CHECKER_HPP

namespace nikitov
{
  class SubmaxChecker
  {
  public:
    SubmaxChecker();
    void operator()(long long int number);
    long long int operator()() const;

  private:
    long long int actualMax_;
    long long int prevMax_;
  };
}
#endif
