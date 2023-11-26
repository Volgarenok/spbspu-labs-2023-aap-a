#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <utility>

namespace skuratov
{
  template < typename T >
  void bubbleSort(T* begin, T* end)
  {
    for (T* i = begin; i != end - 1; ++i)
    {
      for (T* j = begin; j != end - (i - begin) - 1; ++j)
      {
        if (*j > *(j + 1))
        {
          std::swap(*j, *(j + 1));
        }
      }
    }
  }
}

#endif
