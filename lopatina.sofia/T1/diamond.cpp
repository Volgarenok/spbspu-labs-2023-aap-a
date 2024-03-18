#include "diamond.hpp"
#include <cstddef>
#include <cmath>
#include <stdexcept>

lopatina::point_t defineCentralPoint(lopatina::point_t p1, lopatina::point_t p2, lopatina::point_t p3)
{
  if (((p1.x == p2.x) && (p1.y == p3.y)) || ((p1.x == p3.x) && (p1.y == p2.y)))
  {
    return p1;
  }
  else if (((p2.x == p1.x) && (p2.y == p3.y)) || ((p2.x == p3.x) && (p2.y == p1.y)))
  {
    return p2;
  }
  return p3;
}

lopatina::point_t defineSidePointX(lopatina::point_t p1, lopatina::point_t p2, lopatina::point_t p3)
{
  lopatina::point_t centre = defineCentralPoint(p1, p2, p3);
  if ((centre.y == p1.y) && (centre.x != p1.x))
  {
    return p1;
  }
  else if ((centre.y == p2.y) && (centre.x != p2.x))
  {
    return p2;
  }
  return p3;
}

lopatina::point_t defineSidePointY(lopatina::point_t p1, lopatina::point_t p2, lopatina::point_t p3)
{
  lopatina::point_t centre = defineCentralPoint(p1, p2, p3);
  if ((centre.x == p1.x) && (centre.y != p1.y))
  {
    return p1;
  }
  else if ((centre.x == p2.x) && (centre.y != p2.y))
  {
    return p2;
  }
  return p3;
}

lopatina::Diamond::Diamond(point_t p1, point_t p2, point_t p3):
  central_vertex_(defineCentralPoint(p1, p2, p3)),
  side_x_vertex_(defineSidePointX(p1, p2, p3)),
  side_y_vertex_(defineSidePointY(p1, p2, p3))
{
  if (!((central_vertex_.x == side_y_vertex_.x) && (central_vertex_.y != side_y_vertex_.y)))
  {
    throw std::invalid_argument("Figure has wrong parameter\n");
  }
  if (!((central_vertex_.y == side_x_vertex_.y) && (central_vertex_.x != side_x_vertex_.x)))
  {
    throw std::invalid_argument("Figure has wrong parameter\n");
  }
}

double lopatina::Diamond::getArea() const
{
  double diagonal_1 = 2.0 * std::abs(side_y_vertex_.y - central_vertex_.y);
  double diagonal_2 = 2.0 * std::abs(side_x_vertex_.x - central_vertex_.x);
  return diagonal_1 * diagonal_2 / 2.0;
}

lopatina::rectangle_t lopatina::Diamond::getFrameRect() const
{
  double height = 2.0 * std::abs(side_y_vertex_.y - central_vertex_.y);
  double width = 2.0 * std::abs(side_x_vertex_.x - central_vertex_.x);
  rectangle_t newRect{height, width, central_vertex_};
  return newRect;
}

void lopatina::Diamond::move(point_t new_pos)
{
  double dx = new_pos.x - central_vertex_.x;
  double dy = new_pos.y - central_vertex_.y;
  move(dx, dy);
}

void lopatina::Diamond::move(double dx, double dy)
{
  central_vertex_.x += dx;
  central_vertex_.y += dy;
  side_x_vertex_.x += dx;
  side_x_vertex_.y += dy;
  side_y_vertex_.x += dx;
  side_y_vertex_.y += dy;
}

void lopatina::Diamond::scale(double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("Incorrect scale index\n");
  }
  side_x_vertex_.x = central_vertex_.x + (side_x_vertex_.x - central_vertex_.x) * k;
  side_x_vertex_.y = central_vertex_.y + (side_x_vertex_.y - central_vertex_.y) * k;
  side_y_vertex_.x = central_vertex_.x + (side_y_vertex_.x - central_vertex_.x) * k;
  side_y_vertex_.y = central_vertex_.y + (side_y_vertex_.y - central_vertex_.y) * k;
}
