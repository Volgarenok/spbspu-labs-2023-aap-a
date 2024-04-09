#include "complexquad.h"
#include "isoscale.h"

Shape* inputComplexquad(std::istream& input)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  double x3 = 0.0;
  double y3 = 0.0;
  double x4 = 0.0;
  double y4 = 0.0;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  if (!input)
  {
    throw std::logic_error("error");
  }
  return new Complexquad(point_t{x1, y1}, point_t{x2, y2}, point_t{x3, y3}, point_t{x4, y4});
}

point_t findCenter(point_t pos1, point_t pos2, point_t pos3, point_t pos4)
{
  double cx = 0.0;
  double cy = 0.0;
  double a1 = pos1.y - pos2.y;
  double b1 = pos2.x - pos1.x;
  double c1 = pos1.x * pos2.y - pos2.x * pos1.y;
  double a2 = pos3.y - pos4.y;
  double b2 = pos4.x - pos3.x;
  double c2 = pos3.x * pos4.y - pos4.x * pos3.y;
  double det = a1 * b2 - a2 * b1;
  cx = (b1 * c2 - b2 * c1) / det;
  cy = (a2 * c1 - a1 * c2) / det;
  return (point_t{cx, cy});
}

Complexquad::Complexquad(point_t pos1, point_t pos2, point_t pos3, point_t pos4):
  center_(findCenter(pos1, pos2, pos3, pos4)),
  triangle1_(pos1, pos4, center_),
  triangle2_(pos2, pos3, center_)
{}

double Complexquad::getArea() const
{
  return triangle1_.getArea() + triangle2_.getArea();
}

rectangle_t Complexquad::getFrameRect() const
{
  rectangle_t framerectangle1 = triangle1_.getFrameRect();
  rectangle_t framerectangle2 = triangle2_.getFrameRect();
  point_t fr1leftdownpoint = {framerectangle1.pos.x - framerectangle1.width / 2, framerectangle1.pos.y - framerectangle1.height / 2};
  point_t fr1rightuppoint = {framerectangle1.pos.x + framerectangle1.width / 2, framerectangle1.pos.y + framerectangle1.height / 2};
  point_t fr2leftdownpoint = {framerectangle2.pos.x - framerectangle2.width / 2, framerectangle2.pos.y - framerectangle2.height / 2};
  point_t fr2rightuppoint = {framerectangle2.pos.x + framerectangle2.width / 2, framerectangle2.pos.y + framerectangle2.height / 2};
  double maxx = std::max(fr1rightuppoint.x, fr2rightuppoint.x);
  double maxy = std::max(fr1rightuppoint.y, fr2rightuppoint.y);
  double minx = std::min(fr1leftdownpoint.x, fr2leftdownpoint.x);
  double miny = std::min(fr1leftdownpoint.y, fr2leftdownpoint.y);
  return makeFrame(point_t{minx, miny}, point_t{maxx, maxy});
}

void Complexquad::move(point_t point)
{
  return move(point.x - center_.x, point.y - center_.y);
}

void Complexquad::move(double dx, double dy)
{
  triangle1_.move(dx, dy);
  triangle2_.move(dx, dy);
  center_.x += dx;
  center_.y += dy;
}

void Complexquad::scale(double k) noexcept
{
  isoScale(std::addressof(triangle1_), center_, k);
  isoScale(std::addressof(triangle2_), center_, k);
}

Shape* Complexquad::clone() const
{
  return new Complexquad(*this);
}
