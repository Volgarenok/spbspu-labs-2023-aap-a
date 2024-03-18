#include "results_printer.hpp"

#include <iostream>
#include <iomanip>

void belokurskaya::printResults(std::ostream & output, const Shape * const * shapes, size_t shape_count)
{
  output << std::fixed;
  output.precision(1);

  double area = 0;
  for (size_t i = 0; i < shape_count; ++i)
  {
    area += shapes[i]->getArea();
  }
  output << area;
  for (size_t i = 0; i < shape_count; ++i)
  {
    rectangle_t frameRect = shapes[i]->getFrameRect();
    double scale_lower_left_x = frameRect.pos.x - frameRect.width / 2.0;
    double scale_lower_left_y = frameRect.pos.y - frameRect.height / 2.0;
    double scale_upper_right_x = frameRect.pos.x + frameRect.width / 2.0;
    double scale_upper_right_y = frameRect.pos.y + frameRect.height / 2.0;

    output << " " << scale_lower_left_x << " " << scale_lower_left_y << " " << scale_upper_right_x << " " << scale_upper_right_y;
  }
  output << "\n";
}
