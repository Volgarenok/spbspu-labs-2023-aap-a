#include "outputShapes.hpp"

void printVertexes(const rebdev::point_t & upRight, const rebdev::point_t & lowLeft, std::ostream & out)
{
  out << ' ' << lowLeft.x << ' ' << lowLeft.y;
  out << ' ' << upRight.x << ' ' << upRight.y;
}


void rebdev::printShapes(const Shape * const * shapes, size_t numOfShapes, std::ostream & out)
{
  double sum = 0;
  for (size_t i = 0; i < numOfShapes; ++i)
  {
    sum += shapes[i]->getArea();
  }

  out << sum;

  for (size_t i = 0; i < numOfShapes; ++i)
  {
    rectangle_t rect = shapes[i]->getFrameRect();
    point_t lowLeft = {rect.pos.x - (rect.width / 2), rect.pos.y - (rect.height / 2)};
    point_t upRight = {rect.pos.x + (rect.width / 2), rect.pos.y + (rect.height / 2)};
    printVertexes(upRight, lowLeft, out);
  }
}

