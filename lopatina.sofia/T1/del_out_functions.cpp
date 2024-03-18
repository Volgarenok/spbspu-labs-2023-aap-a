#include "del_out_functions.hpp"
#include <cmath>
#include <iomanip>
#include <algorithm>

void lopatina::outputResult(std::ostream & output, const Shape * const * array, size_t counter)
{
  double sum_area = 0.0;
  for (size_t i = 0; i < counter; ++i)
  {
    sum_area += array[i]->getArea();
  }
  output << std::fixed << std::setprecision(1) << sum_area;
  for (size_t i = 0; i < counter; ++i)
  {
    rectangle_t frame = array[i]->getFrameRect();
    double height = frame.height;
    double width = frame.width;
    double pos_x = frame.pos.x;
    double pos_y = frame.pos.y;
    output << ' ' << std::round((pos_x - (width / 2.0)) * 10) / 10 << ' ' << std::round((pos_y - (height / 2.0)) * 10) / 10;
    output << ' ' << std::round((pos_x + (width / 2.0)) * 10) / 10 << ' ' << std::round((pos_y + (height / 2.0)) * 10) / 10;
  }
  output << '\n';
}

void lopatina::deleteArray(Shape ** array, size_t counter)
{
  for (size_t i = 0; i < counter; ++i)
  {
    delete array[i];
  }
}
