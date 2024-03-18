#include "complexquad.hpp"

chistyakov::Complexquad::Complexquad(const point_t & pnt1, const point_t & pnt2, const point_t & pnt3, const point_t & pnt4):
  pnt1_(pnt1),
  pnt2_(pnt2),
  pnt3_(pnt3),
  pnt4_(pnt4)
{
  chistyakov::point_t points[4] = { pnt1, pnt2, pnt3, pnt4 };
  for (int i = 0; i < 4; ++i)
  {
    chistyakov::point_t nowPoint = points[i];

    for (int j = i + 1; j < 4; ++j)
    {
      if (nowPoint.x == points[j].x && nowPoint.y == points[j].y)
      {
        throw std::invalid_argument("Invalid argument for points in complexquad");
      }
    }
  }

  double n = 0;
  if (pnt2.y - pnt1.y != 0)
  {
    double q = (pnt2.x - pnt1.x) / (pnt1.y - pnt2.y);
    double sn = (pnt3.x - pnt4.x) + (pnt3.y - pnt4.y) * q;
    if (!sn)
    {
      throw std::invalid_argument("The lines don't intersect");
    }
    double fn = (pnt3.x - pnt1.x) + (pnt3.y - pnt1.y) * q;
    n = fn / sn;
  }
  else
  {
    if (!(pnt3.y - pnt4.y))
    {
      throw std::invalid_argument("The lines don't intersect");
    }
    n = (pnt3.y - pnt1.y) / (pnt3.y - pnt4.y);
  }

  cross_.x = pnt3.x + (pnt4.x - pnt3.x) * n;
  cross_.y = pnt3.y + (pnt4.y - pnt3.y) * n;
}

chistyakov::Complexquad::~Complexquad() = default;

double chistyakov::Complexquad::getArea() const
{
  double area1 = (pnt1_.x * (pnt4_.y - cross_.y) + pnt4_.x * (cross_.y - pnt1_.y) + cross_.x * (pnt1_.y - pnt4_.y)) / 2.0;
  double area2 = (pnt2_.x * (pnt3_.y - cross_.y) + pnt3_.x * (cross_.y - pnt2_.y) + cross_.x * (pnt2_.y - pnt3_.y)) / 2.0;
  return area1 + area2;
}

chistyakov::rectangle_t chistyakov::Complexquad::getFrameRect() const
{
  chistyakov::point_t points[3] = { pnt2_, pnt3_, pnt4_ };
  chistyakov::point_t leftCorner = {pnt1_.x, pnt1_.y};
  chistyakov::point_t rightCorner = {pnt1_.x, pnt1_.y};

  for (int i = 0; i < 3; ++i)
  {
    if (leftCorner.x < points[i].x)
    {
      leftCorner.x = points[i].x;
    }
    if (leftCorner.y < points[i].y)
    {
      leftCorner.y = points[i].y;
    }
    if (rightCorner.x > points[i].x)
    {
      rightCorner.x = points[i].x;
    }
    if (rightCorner.y > points[i].y)
    {
      rightCorner.y = points[i].y;
    }
  }

  double width = rightCorner.x - leftCorner.x;
  double height = rightCorner.y - leftCorner.y;
  chistyakov::point_t pos = { width/2.0 + leftCorner.x, height/2.0 + leftCorner.y};
  return {width, height, pos};
}

void chistyakov::Complexquad::move(const point_t & point)
{
  rectangle_t area = getFrameRect();
  double mx = point.x - area.pos.x;
  double my = point.y - area.pos.y;
  move(mx, my);
}

void chistyakov::Complexquad::move(double mx, double my)
{
  chistyakov::point_t points[4] = { pnt1_, pnt2_, pnt3_, pnt4_ };
  for (int i = 0; i < 4; ++i)
  {
    points[i].x += mx;
    points[i].y += my;
  }
  cross_.x += mx;
  cross_.y += my;
}

void chistyakov::Complexquad::scale(double ratio)
{
  chistyakov::point_t points[4] = { pnt1_, pnt2_, pnt3_, pnt4_ };
  for (int i = 0; i < 4; ++i)
  {
    points[i].x = cross_.x + (points[i].x - cross_.x) * ratio;
    points[i].y = cross_.y + (points[i].y - cross_.y) * ratio;
  }
}
