#include "shapes_i_o.hpp"
#include <string>
#include <stdexcept>
#include <cstddef>
#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "complexquad.hpp"
#include "parallelogram.hpp"
#include "geometric_functions.hpp"

double zaitsev::readValue(std::istream& input)
{
  double val = 0;
  input >> val;
  if (!input)
  {
    throw std::invalid_argument("The value must be a number");
  }
  return val;
}

void zaitsev::readPoint(std::istream& input, point_t& dest)
{
  dest.x = readValue(input);
  dest.y = readValue(input);
}

void zaitsev::readArray(std::istream& input, point_t* dest, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    readPoint(input, dest[i]);
  }
}

zaitsev::Shape* zaitsev::readRectangle(std::istream& input)
{
  point_t left = { 0, 0 };
  point_t right = { 0, 0 };
  readPoint(input, left);
  readPoint(input, right);
  return new Rectangle(left, right);;
}

zaitsev::Shape* zaitsev::readComplexquad(std::istream& input)
{
  point_t vertices[4] = {};
  readArray(input, vertices, 4);
  return new Complexquad(vertices[0], vertices[1], vertices[2], vertices[3]);
}

zaitsev::Shape* zaitsev::readParallelogram(std::istream& input)
{
  point_t vertices[3] = {};
  readArray(input, vertices, 3);
  return new Parallelogram(vertices[0], vertices[1], vertices[2]);
}

void zaitsev::readScale(std::istream& input, point_t& center, double& factor)
{
  readPoint(input, center);
  factor = readValue(input);
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive");
  }
}

std::ostream& zaitsev::shapesOutput(std::ostream& output, const Shape* const* shapes, size_t size)
{
  std::ios format_holder(nullptr);
  format_holder.copyfmt(output);
  output.precision(1);
  output.setf(std::ios::fixed);

  double area = 0;
  for (size_t i = 0; i < size; ++i)
  {
    area += shapes[i]->getArea();
  }
  output << area;
  for (size_t i = 0; i < size; ++i)
  {
    rectangle_t frame = shapes[i]->getFrameRect();
    output << " " << frame.pos.x - frame.width / 2 << " " << frame.pos.y - frame.height / 2;
    output << " " << frame.pos.x + frame.width / 2 << " " << frame.pos.y + frame.height / 2;
  }
  output.copyfmt(format_holder);
  return output;
}

void zaitsev::freeShapes(Shape** shapes, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shapes[i];
  }
}
