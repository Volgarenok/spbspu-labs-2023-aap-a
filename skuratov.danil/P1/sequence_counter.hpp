#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <cstddef>
namespace skuratov
{
    struct SequenceCounter
    {
        SequenceCounter();
        void operator()(int);
        size_t operator()() const;
        //void count_max(int);
    private:
        int number;
        size_t count_;
    };
}
#endif