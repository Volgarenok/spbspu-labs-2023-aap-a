#include "circle.hpp"
#include <stdexcept>
#include "geometryFunctions.hpp"

isaychev::Circle::Circle(const point_t & p, double rad):
  center_(p),
  radius_(rad)
{
  if (radius_ <= 0.0)
  {
    throw std::logic_error("Incorrect circle parameters");
  }
}

double isaychev::Circle::getArea() const
{
  return 3.1415926535 * radius_ * radius_;
}

isaychev::rectangle_t isaychev::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, {center_.x, center_.y}};
}

void isaychev::Circle::move(const point_t & newPos)
{
  center_ = {newPos.x, newPos.y};
}

void isaychev::Circle::move(double dX, double dY)
{
  changeCoords(center_, dX, dY);
}

void isaychev::Circle::doScale(double coeff)
{
  radius_ *= coeff;
}
