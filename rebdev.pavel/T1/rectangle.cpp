#include "rectangle.hpp"

rebdev::Rectangle::Rectangle():
  lowLeftAngle_(point_t{0.0, 0.0}),
  upRightAngle_(point_t{0.0, 0.0})
{};
rebdev::Rectangle::Rectangle(const point_t & lowLeftAngle, const point_t & upRightAngle):
  lowLeftAngle_(point_t{0.0, 0.0}),
  upRightAngle_(point_t{0.0, 0.0})
{
  if ((upRightAngle.x_ < lowLeftAngle.x_) || (upRightAngle.y_ < lowLeftAngle.y_))
  {
    lowLeftAngle_ = upRightAngle;
    upRightAngle_ = lowLeftAngle;
  }
  else
  {
    lowLeftAngle_ = lowLeftAngle;
    upRightAngle_ = upRightAngle;
  }
};
rebdev::Rectangle::Rectangle(const double xLLA, const double yLLA, const double xURA, const double yURA):
  lowLeftAngle_(point_t{0.0, 0.0}),
  upRightAngle_(point_t{0.0, 0.0})
{
  if ((xURA < xLLA) || (yURA < yLLA))
  {
    lowLeftAngle_ = point_t{xURA, yURA};
    upRightAngle_ = point_t{xLLA, yLLA};
  }
  else
  {
    lowLeftAngle_ = point_t{xLLA, yLLA};
    upRightAngle_ = point_t{xURA, yURA};
  }
};


double rebdev::Rectangle::getArea() const
{
  return  ((upRightAngle_.x_ - lowLeftAngle_.x_) * (upRightAngle_.y_ - lowLeftAngle_.y_));
};

rebdev::rectangle_t rebdev::Rectangle::getFrameRect()
{
  double width = upRightAngle_.x_ - lowLeftAngle_.x_;
  double height = upRightAngle_.y_ - lowLeftAngle_.y_;
  point_t pos = {(upRightAngle_.x_ + lowLeftAngle_.x_)/2, (upRightAngle_.y_ + lowLeftAngle_.y_)/2};
  return rectangle_t{width, height, pos};
};

void rebdev::Rectangle::move(const point_t point)
{
  rectangle_t frameRectangle = getFrameRect();

  double yChange = frameRectangle.pos_.y_ - point.y_;
  double xChange = frameRectangle.pos_.x_ - point.x_;

  upRightAngle_.y_ += yChange;
  upRightAngle_.x_ += xChange;
  lowLeftAngle_.y_ += yChange;
  lowLeftAngle_.x_ += xChange;
};

void rebdev::Rectangle::move(const double x, const double y)
{
  lowLeftAngle_.x_ += x;
  lowLeftAngle_.y_ += y;
  upRightAngle_.x_ += x;
  upRightAngle_.y_ += y;
};

void rebdev::Rectangle::scale(const double k)
{
  rectangle_t frameRectangle = getFrameRect();

  upRightAngle_.x_ = (upRightAngle_.x_ - frameRectangle.pos_.x_) * k + frameRectangle.pos_.x_;
  upRightAngle_.y_ = (upRightAngle_.y_ - frameRectangle.pos_.y_) * k + frameRectangle.pos_.y_;
  lowLeftAngle_.x_ = (lowLeftAngle_.x_ - frameRectangle.pos_.x_) * k + frameRectangle.pos_.x_;
  lowLeftAngle_.y_ = (lowLeftAngle_.y_ - frameRectangle.pos_.y_) * k + frameRectangle.pos_.y_;
};
