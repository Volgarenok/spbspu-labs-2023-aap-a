#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

skuratov::SequenceCounter::SequenceCounter():
    count_(0)
{}

void skuratov::SequenceCounter::operator()(int number)
{
    size_t max_size = std::numeric_limits< size_t >::max();
    if (count_ == max_size)
    {
        throw std::logic_error("sequence is too long");
    }
    static int max_number = 0;
    if (number > max_number)
    {
        max_number = number;
        count_ = 0;
    }
    else if (max_number == number)
    {
        ++count_;
    }
}
size_t skuratov::SequenceCounter::operator()() const
{
    return count_ + 1;
}
