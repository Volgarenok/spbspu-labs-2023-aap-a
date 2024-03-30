#include "diamond.hpp"

#include <stdexcept>
#include "shape-creation.hpp"

arakelyan::Diamond::Diamond(const point_t fp, const point_t sp, const point_t tp):
  p1_(fp),
  p2_(sp),
  p3_(tp)
{
  if (!(p1_.y == p2_.y || p1_.y == p3_.y || p2_.y == p3_.y))
  {
    throw std::logic_error("Diagonals of the DIAMOND are not parallel to the axes!");
  }
}

double arakelyan::Diamond::getArea() const
{
  rectangle_t dataOfFrameRect = getFrameRect();
  return std::abs((dataOfFrameRect.height * dataOfFrameRect.width) / 2.0);
}

arakelyan::rectangle_t arakelyan::Diamond::getFrameRect() const
{
  double width = std::abs(p2_.x - p1_.x) * 2.0;
  double height = std::abs(p3_.y - p2_.y) * 2.0;
  point_t midPoint = p2_;
  return {width, height, midPoint};
}

void arakelyan::Diamond::move(const point_t point)
{
  rectangle_t data = getFrameRect();
  double delX = point.x - data.pos.x;
  double delY = point.y - data.pos.y;
  move(delX, delY);
}

void arakelyan::Diamond::move(const double delX, const double delY)
{
  point_t * pointsArray[3] = {&p1_, &p2_, &p3_};
  for (size_t i = 0; i < 3; i++)
  {
    pointsArray[i]->x += delX;
    pointsArray[i]->y += delY;
  }
}

void arakelyan::Diamond::scaleShape(const double k)
{
  rectangle_t dataOfFrameRect = getFrameRect();
  scaleForParAndDiam(dataOfFrameRect, p1_, p2_, p3_, k);
}
