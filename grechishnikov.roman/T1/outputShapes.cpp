#include "outputShapes.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "polygon.hpp"

double getTotalArea(const grechishnikov::Shape* const* shapes, size_t size);

void grechishnikov::outputShapes(std::ostream& out, const Shape* const* shapes, size_t size)
{
  out << std::fixed;
  out.precision(1);
  out << getTotalArea(shapes, size);
  for (size_t i = 0; i < size; i++)
  {
    point_t pos = shapes[i]->getFrameRect().pos;
    double width = shapes[i]->getFrameRect().width;
    double height = shapes[i]->getFrameRect().height;
    out << ' ' << pos.x - width / 2.0 << ' ' << pos.y - height / 2.0;
    out << ' ' << pos.x + width / 2.0 << ' ' << pos.y + height / 2.0;
  }
  out << std::defaultfloat;
}

double getTotalArea(const grechishnikov::Shape* const* shapes, size_t size)
{
  double totalArea = 0;
  for (size_t i = 0; i < size; i++)
  {
    totalArea += shapes[i]->getArea();
  }
  return totalArea;
}
