#include "scale.hpp"
#include "output.hpp"

void sakovskaia::scaleOp(const char * string, Shape * const * shapes, size_t cnt, std::ostream & output)
{
  size_t c = 0;
  const char * arg_string = string + 6;
  double args[3]{};
  for (size_t i = 0; i < 3; ++i)
  {
    args[i] = std::stod(arg_string, std::addressof(c));
    arg_string += c;
  }
  scaleShapes(shapes, cnt, args, output);
}

void sakovskaia::isoScaleShapes(Shape * shape, point_t scalePoint, double scaleRatio)
{
  rectangle_t frameRect = shape->getFrameRect();
  point_t startPoint = frameRect.pos;
  shape->move(scalePoint);
  shape->scale(scaleRatio);
  shape->move((startPoint.x - scalePoint.x) * scaleRatio, (startPoint.y - scalePoint.y) * scaleRatio);
}

void sakovskaia::scaleShapes(Shape * const * shapes, size_t cnt, const double * args, std::ostream& output)
{
  if (cnt == 0)
  {
    throw std::logic_error("No shapes");
  }
  if (args[2] < 0)
  {
    throw std::logic_error("Invalid scale argument");
  }
  const point_t center = {args[0], args[1]};
  outputShapes(output, shapes, cnt);
  for (size_t i = 0; i < cnt; i++)
  {
    isoScaleShapes(shapes[i], center, args[2]);
  }
  outputShapes(output, shapes, cnt);
}
