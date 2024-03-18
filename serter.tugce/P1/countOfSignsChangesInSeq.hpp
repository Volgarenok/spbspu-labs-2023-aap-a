#ifndef COUNTOFSIGNSCHANGESINSEQ_HPP
#define COUNTOFSIGNSCHANGESINSEQ_HPP

#include <cstddef>
namespace serter
{
  struct CountOfSignsChangesInSeq
  {
    CountOfSignsChangesInSeq();
    void operator()(int);
    size_t operator()() const;
  private:
    size_t countOfMembersOfSeq_;
    int currentNumber_;
    size_t count_;
  };
}

#endif

