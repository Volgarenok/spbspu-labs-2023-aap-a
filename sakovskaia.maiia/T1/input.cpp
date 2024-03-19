#include "input.hpp"
#include <cstddef>
#include <cstring>
#include <string>

void sakovskaia::coorShape(const char * string, double * coordinates, size_t cnt)
{
  size_t cnt_points = 0;
  for (size_t i = 0; i < cnt; ++i)
  {
    coordinates[i] = std::stod(string, & cnt_points);
    string += cnt_points;
  }
}

sakovskaia::Shape * sakovskaia::inputRectangle(const char * string)
{
  double rectangleCoordinates[4]{};
  coorShape(string, rectangleCoordinates, 4);
  point_t ll = {rectangleCoordinates[0], rectangleCoordinates[1]};
  point_t ur = {rectangleCoordinates[2], rectangleCoordinates[3]};
  return new Rectangle(ll, ur);
}

sakovskaia::Shape * sakovskaia::inputParallelogram(const char * string)
{
  double parallelogramCoordinates[6]{};
  coorShape(string, parallelogramCoordinates, 6);
  point_t p1 = {parallelogramCoordinates[0], parallelogramCoordinates[1]};
  point_t p2 = {parallelogramCoordinates[2], parallelogramCoordinates[3]};
  point_t p3 = {parallelogramCoordinates[4], parallelogramCoordinates[5]};
  return new Parallelogram(p1, p2, p3);
}

sakovskaia::Shape * sakovskaia::inputSquare(const char * string)
{
  double squareCoordinates[3]{};
  coorShape(string, squareCoordinates, 3);
  point_t ll = {squareCoordinates[0], squareCoordinates[1]};
  double length = squareCoordinates[2];
  return new Square(ll, length);
}

sakovskaia::Shape * sakovskaia::inputEllipse(const char * string)
{
  double ellipseCoordinates[4]{};
  coorShape(string, ellipseCoordinates, 4);
  point_t center = {ellipseCoordinates[0], ellipseCoordinates[1]};
  return new Ellipse(center, ellipseCoordinates[2], ellipseCoordinates[3]);
}
