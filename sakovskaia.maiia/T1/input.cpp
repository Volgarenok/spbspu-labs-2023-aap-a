#include "input.hpp"
#include <stddef>

void sakovskaia::inputFigure(const char * string, double * coordinates, size_t cnt_points)
{
  size_t cnt_points = 0;
  for (size_t i = 0; i < cnt_points; ++i)
  {
    coordinates[i] = std::stod(string, & cnt_points);
    string += cnt_points;
  }
}
