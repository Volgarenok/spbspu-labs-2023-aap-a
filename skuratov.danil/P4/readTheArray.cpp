#include "readTheArray.h"

#include <cctype>
#include <cstddef>
#include <iostream>

namespace skuratov
{
  std::istream& readTheArray(std::istream& in, size_t sizeOfFileArray, int* fileArray)
  {
    for (size_t i = 0; i < sizeOfFileArray; i++)
    {
      in >> fileArray[i];
      if (!in)
      {
        return in;
      }
    }
    return in;
  }
}
