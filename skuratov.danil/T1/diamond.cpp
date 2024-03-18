#include "diamond.hpp"

#include <stdexcept>
#include <cmath>
#include <algorithm>

skuratov::Diamond::Diamond(const point_t& corner1, const point_t& corner2, const point_t& corner3):
  c1(corner1),
  c2(corner2),
  c3(corner3)
{
  if (!((c1.x == c2.x && c2.y == c3.y) || (c1.x == c3.x && c1.y == c2.y) || (c1.y == c2.y && c2.x == c3.x)))
  {
    throw std::invalid_argument("Error: diagonals of the diamond must be parallel to the coordinate axes");
  }
}

double skuratov::Diamond::getArea() const
{
  double diagonal1 = std::sqrt(std::pow(c1.x - c3.x, 2) + std::pow(c1.y - c3.y, 2));
  double diagonal2 = std::sqrt(std::pow(c1.x - c2.x, 2) + std::pow(c1.y - c2.y, 2));
  return (diagonal1 * diagonal2) / 2;
}

skuratov::rectangle_t skuratov::Diamond::getFrameRect() const
{
  double minX = std::min({ c1.x, c2.x, c3.x });
  double maxX = std::max({ c1.x, c2.x, c3.x });
  double minY = std::min({ c1.y, c2.y, c3.y });
  double maxY = std::max({ c1.y, c2.y, c3.y });

  double width = maxX - minX;
  double height = maxY - minY;
  point_t pos = { minX + width / 2, minY + height / 2 };
  return { width, height, pos };
}

void skuratov::Diamond::move(const point_t& A)
{
  rectangle_t B = getFrameRect();
  move(A.x - B.pos.x, A.y - B.pos.y);
}

void skuratov::Diamond::move(double dx, double dy)
{
  point_t vertices[] = { c1, c2, c3 };

  for (int i = 0; i < 3; ++i)
  {
    vertices[i].x += dx;
    vertices[i].y += dy;
  }
  c1 = vertices[0];
  c2 = vertices[1];
  c3 = vertices[2];
}

void skuratov::Diamond::scale(double scalingFactor)
{
  if (scalingFactor <= 0)
  {
    throw std::invalid_argument("Error: scale factor of diamond should be a positive");
  }

  rectangle_t B = getFrameRect();
  point_t center = B.pos;

  point_t points[] = { c1, c2, c3 };
  for (auto& point : points)
  {
    point.x = center.x + scalingFactor * (point.x - center.x);
    point.y = center.y + scalingFactor * (point.y - center.y);
  }
}
