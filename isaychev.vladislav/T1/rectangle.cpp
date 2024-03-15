#include "rectangle.hpp"
#include <stdexcept>
#include "geometryFunctions.hpp"

isaychev::Rectangle::Rectangle(const point_t & p1, const point_t & p2):
  botL_(p1),
  topR_(p2)
{
  if (botL_.x >= topR_.x || botL_.y >= topR_.y)
  {
    throw std::logic_error("Incorrect rectangle parameters");
  }
}

double isaychev::Rectangle::getArea() const
{
  return (topR_.x - botL_.x) * (topR_.y - botL_.y);
}

isaychev::rectangle_t isaychev::Rectangle::getFrameRect() const
{
  double wdth = topR_.x - botL_.x;
  double hght = topR_.y - botL_.y;
  point_t ps = {(topR_.x + botL_.x) / 2, (topR_.y + botL_.y) / 2};
  return {wdth, hght, ps};
}

void isaychev::Rectangle::move(const point_t & newPos)
{
  double width = topR_.x - botL_.x;
  double height = topR_.y - botL_.y;
  topR_ = {newPos.x + (width / 2), newPos.y + (height / 2)};
  botL_ = {newPos.x - (width / 2), newPos.y - (height / 2)};
}

void isaychev::Rectangle::move(double dX, double dY)
{
  changeCoords(topR_, dX, dY);
  changeCoords(botL_, dX, dY);
}

void isaychev::Rectangle::doScale(double coeff)
{
  double width05 = (topR_.x - botL_.x) / 2;
  double height05 = (topR_.y - botL_.y) / 2;
  topR_.x += (coeff - 1.0) * width05;
  topR_.y += (coeff - 1.0) * height05;
  botL_.x -= (coeff - 1.0) * width05;
  botL_.y -= (coeff - 1.0) * height05;
}
