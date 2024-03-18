#ifndef READER_HPP
#define READER_HPP

#include <iostream>

#include "base-types.hpp"

namespace belokurskaya
{
  void readPointsArray(std::istream & inputStream, point_t * points, int numPoints)
  {
    for (int i = 0; i < numPoints; ++i)
    {
      inputStream >> points[i].x >> points[i].y;
    }
  }
}

#endif
