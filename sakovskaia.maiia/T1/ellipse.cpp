#include "ellipse.hpp"

sakovskaia::Ellipse::Ellipse(point_t center, double radiusX, double radiusY):
  center_(center),
  radiusX_(radiusX),
  radiusY_(radiusY)
{}

double sakovskaia::Ellipse::getArea() const
{
  const double pi = 3.14;
  return pi * radiusX_ * radiusY_;
}
