#include "diamond.hpp"
#include <stdexcept>

lebedev::point_t findCenter(const lebedev::point_t & p1, const lebedev::point_t & p2, const lebedev::point_t & p3)
{
  if ((p1.x == p2.x && p1.y == p3.y) || (p1.x == p3.x && p1.y == p2.y))
  {
    return p1;
  }
  else if ((p2.x == p1.x && p2.y == p3.y) || (p2.x == p3.x && p2.y == p1.y))
  {
    return p2;
  }
  else
  {
    return p3;
  }
}

lebedev::point_t findSecond(const lebedev::point_t & p1, const lebedev::point_t & p2, const lebedev::point_t & p3)
{
  lebedev::point_t center = findCenter(p1, p2, p3);
  if (p1.y == center.y && p1.x != center.x)
  {
    return p1;
  }
  else if (p2.y == center.y && p2.x != center.x)
  {
    return p2;
  }
  else
  {
    return p3;
  }
}

lebedev::point_t findThird(const lebedev::point_t & p1, const lebedev::point_t & p2, const lebedev::point_t & p3)
{
  lebedev::point_t center = findCenter(p1, p2, p3);
  if (p1.x == center.x && p1.y != center.y)
  {
    return p1;
  }
  else if (p2.x == center.x && p2.y != center.y)
  {
    return p2;
  }
  else
  {
    return p3;
  }
}

lebedev::Diamond::Diamond(const point_t & p1, const point_t & p2, const point_t & p3) :
  p1_(findCenter(p1, p2, p3)),
  p2_(findSecond(p1, p2, p3)),
  p3_(findThird(p1, p2, p3))
{
  bool correct_figure = true;
  if (!((p1_.x == p2_.x && p1_.y == p3_.y) || (p1_.x == p3_.x && p1_.y == p2_.y)))
  {
    correct_figure = false;
  }
  else if (!(p2_.y == p1_.y && p2_.x != p1_.x))
  {
    correct_figure = false;
  }
  else if (!(p3_.x == p1_.x && p3_.y != p1_.y))
  {
    correct_figure = false;
  }
  if (!correct_figure)
  {
    throw std::invalid_argument("Error: invalid arguments for the Diamond");
  }
}
double lebedev::Diamond::getArea() const
{
  double a = std::abs(p1_.x - p2_.x);
  double b = std::abs(p1_.y - p3_.y);
  return 2 * a * b;
}
lebedev::rectangle_t lebedev::Diamond::getFrameRect() const
{
  double width = std::abs(p1_.x - p2_.x) * 2;
  double height = std::abs(p1_.y - p3_.y) * 2;
  return {width, height, p1_};
}
void lebedev::Diamond::move(const point_t & p)
{
  double dx = p.x - p1_.x;
  double dy = p.y - p1_.y;
  move(dx, dy);
}
void lebedev::Diamond::move(double dx, double dy)
{
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
}
void lebedev::Diamond::doScale(double ratio)
{
  p2_ = scalePoint(p2_, p1_, ratio);
  p3_ = scalePoint(p3_, p1_, ratio);
}
