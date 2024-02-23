#include "definedata.hpp"

#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "parallelogram.hpp"

void gladyshev::inputPoints(std::istream& in, double * arrcords, size_t counter)
{
  for (size_t i = 0; i < counter; ++i)
  {
    in >> arrcords[i];
    if (!in)
    {
      throw std::logic_error("bad input of data");
    }
  }
}

void gladyshev::freeMemory(Shape ** shapes, size_t amount)
{
  for (size_t i = 0; i < amount; ++i)
  {
    delete shapes[i];
  }
}

gladyshev::Shape * gladyshev::identifyShape(const std::string& inputName, std::istream& in)
{
  const char * names[] = { "RECTANGLE", "PARALLELOGRAM", "CIRCLE" };
  double p[6]{};
  for (size_t i = 0; i < 3; ++i)
  {
    if (inputName != names[i])
    {
      continue;
    }
    switch (i)
    {
      case 0:
        inputPoints(in, p, 4);
        return new Rectangle({ p[0], p[1] }, { p[2], p[3] });
      case 1:
        inputPoints(in, p, 6);
        return new Parallelogram({ p[0], p[1] }, { p[2], p[3] }, { p[4], p[5] });
      case 2:
        inputPoints(in, p, 3);
        return new Circle({ p[0], p[1] }, p[2]);
    }
  }
  throw std::invalid_argument("not a figure");
}

void gladyshev::isoScale(Shape * shapes, point_t pos, double factor)
{
  rectangle_t frame = shapes->getFrameRect();
  double posfinishx = frame.pos.x;
  double posfinishy = frame.pos.y;
  shapes->move(pos);
  shapes->scale(factor);
  shapes->move(-(pos.x - posfinishx) * factor, -(pos.y - posfinishy) * factor);
}

void gladyshev::scalePoint(point_t& p, double factor, rectangle_t frame)
{
  p.x = p.x - (frame.pos.x - p.x) * (factor - 1);
  p.y = p.y - (frame.pos.y - p.y) * (factor - 1);
}
