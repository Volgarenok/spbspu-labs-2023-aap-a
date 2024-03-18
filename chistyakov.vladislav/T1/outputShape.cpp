#include "outputShape.hpp"

void chistyakov::outputShape(std::ostream & output, const Shape * const * shapes, size_t size)
{
  if (size == 0)
  {
    throw std::logic_error("The list of shapes is empty!");
  }

  output << std::fixed;
  output.precision(1);

  double fullArea = 0.0;
  for (size_t i = 0; i < size; ++i)
  {
    if (shapes[i] == nullptr)
    {
      break;
    }
    fullArea += shapes[i]->getArea();
  }

  output << fullArea;

  point_t downLeft = { 0.0, 0.0 };
  point_t topRight = { 0.0, 0.0 };
  rectangle_t rectangle = { 0.0, 0.0, { 0.0, 0.0 } };

  for (size_t i = 0; i < size; ++i)
  {
    rectangle = shapes[i]->getFrameRect();
    downLeft = {rectangle.pos.x - rectangle.width / 2.0, rectangle.pos.y - rectangle.height / 2.0};
    topRight = {rectangle.pos.x + rectangle.width / 2.0, rectangle.pos.y + rectangle.height / 2.0};
    output << " " << downLeft.x << " " << downLeft.y << " " << topRight.x << " " << topRight.y;
  }

  output << "\n";
}
