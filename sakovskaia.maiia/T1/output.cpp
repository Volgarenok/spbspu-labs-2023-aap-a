#include "output.hpp"
#include <ostream>

void sakovskaia::outputShapes(std::ostream & output, const Shape * const shapes, size_t count)
{
  double sum = 0;
  for (size_t i = 0; i < count; i++)
  {
    sum += shapes[i]->getArea();
  }
  output << sum;
  for (size_t i = 0; i < count; i++)
  {
    rectangle_t rectangle = shapes[i]->getFrameRect();
    double ll_x = rectangle.pos.x - rectangle.width / 2;
    double ll_y = rectangle.pos.y - rectangle.height / 2;
    double ur_x = rectangle.pos.x - rectangle.width / 2;
    double ur_y = rectangle.pos.y - rectangle.height / 2;
    output << " " << ll_x << " " << ll_y << " " << ur_x << " " << ur_y;
  }
  output << "\n";
}

void sakovskaia::freeShapes(Shape ** shapes, size_t cnt)
{
  for (size_t i = 0; i < cnt; ++i)
  {
    delete shapes[i];
  }
}
