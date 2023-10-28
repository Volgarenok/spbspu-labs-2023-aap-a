#ifndef GRTLSS_HPP
#define GRTLSS_HPP

#include <cstddef>
namespace mySpace
{
    struct grt_lss
    {
        grt_lss();
        void firstNumber(size_t number);
        void middleNumber(size_t number);
        void countGRT(size_t number);
        size_t get_result_grt() const;
    private:
        size_t fstNum;
        size_t midNum;
        size_t counter;
    };
};

#endif
