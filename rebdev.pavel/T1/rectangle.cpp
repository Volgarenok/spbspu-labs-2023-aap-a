#include "rectangle.hpp"
#include <stdexcept>
#include "figureFunction.hpp"

rebdev::Rectangle::Rectangle(const point_t & lowLeftCorner, const point_t & upRightCorner):
  corners_{lowLeftCorner, upRightCorner}
{
  if ((corners_[0].x >= corners_[1].x) || (corners_[0].y >= corners_[1].y))
  {
    throw std::logic_error("rectangle error");
  }
}

double rebdev::Rectangle::getArea() const
{
  return ((corners_[1].x - corners_[0].x) * (corners_[1].y - corners_[0].y));
}

rebdev::rectangle_t rebdev::Rectangle::getFrameRect() const
{
  return getFrameRectangle(corners_, 2);
}

void rebdev::Rectangle::move(const point_t & point)
{
  rectangle_t frameRectangle = getFrameRect();
  move(point.x - frameRectangle.pos.x, point.y - frameRectangle.pos.y);
}

void rebdev::Rectangle::move(double x, double y)
{
  movePoints(x, y, corners_, 2);
}

void rebdev::Rectangle::scale(double k)
{
  scaleFigure(corners_, 2, getFrameRect().pos, k);
}
