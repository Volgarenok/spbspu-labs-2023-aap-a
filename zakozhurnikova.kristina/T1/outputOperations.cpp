#include "outputOperations.hpp"
#include "shape.hpp"
#include "square.hpp"

double getFullArea(const zakozhurnikova::Shape* const* shapes, size_t size)
{
  double result = 0.0;
  for (size_t i = 0; i < size; ++i)
  {
    result += shapes[i]->getArea();
  }
  return result;
}

void zakozhurnikova::showCoordinates(std::ostream& out, const rectangle_t& rec)
{
  point_t downLeft = {rec.pos.x - rec.width / 2.0, rec.pos.y - rec.height / 2.0};
  point_t upRight = {rec.pos.x + rec.width / 2.0, rec.pos.y + rec.height / 2.0};
  out << downLeft.x << ' ' << downLeft.y << ' ' << upRight.x << ' ' << upRight.y;
}

void zakozhurnikova::printShapes(std::ostream& output, const Shape* const* shapes, size_t size)
{
  if (size == 0)
  {
    throw std::invalid_argument("Nothing to print");
  }
  output << std::fixed;
  output.precision(1);

  output << getFullArea(shapes, size);
  for (size_t i = 0; i < size; ++i)
  {
    output << ' ';
    showCoordinates(output, shapes[i]->getFrameRect());
  }
  output << '\n';
}
