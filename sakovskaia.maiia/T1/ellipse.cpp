#include "ellipse.hpp"
#include <stdexcept>

sakovskaia::Ellipse::Ellipse(point_t center, double radiusX, double radiusY):
  center_(center),
  radiusX_(radiusX),
  radiusY_(radiusY)
{
  if ((radiusX <= 0) || (radiusY <= 0))
  {
    throw std::invalid_argument("Invalid arguments for ellipse");
  }
}

double sakovskaia::Ellipse::getArea() const
{
  const double pi = 3.14;
  return pi * radiusX_ * radiusY_;
}

sakovskaia::rectangle_t
sakovskaia::Ellipse::getFrameRect() const
{
  double height = radiusY_ * 2;
  double width = radiusX_ * 2;
  point_t center = center_;
  return {width, height, center};
}

void sakovskaia::Ellipse::move(const point_t & new_center)
{
  center_ = new_center;
}

void sakovskaia::Ellipse::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void sakovskaia::Ellipse::scaleEllipse(double k)
{
  radiusX_ *= k;
  radiusY_ *= k;
}

