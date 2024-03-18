#include "input.hpp"
#include <stddef>

void sakovskaia::coordinates(const size_t cnt_points, double * coords_array, point_t * points)
{
  for (size_t i = 0; i < cnt_points; ++i)
  {
    size_t index = i * 2;
    points[i] = {coords_array[index], coords_array[index + 1]};
  }
}
