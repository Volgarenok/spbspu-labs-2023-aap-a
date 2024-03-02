#include "concave.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

spiridonov::Concave::Concave(point_t p1, point_t p2, point_t p3, point_t p4) :
  arrayOfPoints_{ p1, p2, p3, p4 }
{
}

double spiridonov::Concave::getArea() const
{
  double area = 0.25 * std::fabs(
    arrayOfPoints_[0].x * (arrayOfPoints_[1].y - arrayOfPoints_[2].y) +
    arrayOfPoints_[1].x * (arrayOfPoints_[2].y - arrayOfPoints_[0].y) +
    arrayOfPoints_[2].x * (arrayOfPoints_[0].y - arrayOfPoints_[1].y) +
    arrayOfPoints_[3].x * (arrayOfPoints_[0].y - arrayOfPoints_[2].y) +
    arrayOfPoints_[3].x * (arrayOfPoints_[1].y - arrayOfPoints_[0].y) +
    arrayOfPoints_[3].x * (arrayOfPoints_[2].y - arrayOfPoints_[1].y)
  );
  return area;
}

spiridonov::rectangle_t spiridonov::Concave::getFrameRect() const
{
  double minX = std::min({ arrayOfPoints_[0].x, arrayOfPoints_[1].x, arrayOfPoints_[2].x, arrayOfPoints_[3].x });
  double minY = std::min({ arrayOfPoints_[0].y, arrayOfPoints_[1].y, arrayOfPoints_[2].y, arrayOfPoints_[3].y });
  double maxX = std::max({ arrayOfPoints_[0].x, arrayOfPoints_[1].x, arrayOfPoints_[2].x, arrayOfPoints_[3].x });
  double maxY = std::max({ arrayOfPoints_[0].y, arrayOfPoints_[1].y, arrayOfPoints_[2].y, arrayOfPoints_[3].y });

  double width = maxX - minX;
  double height = maxY - minY;

  point_t center{ (minX + maxX) / 2, (minY + maxY) / 2 };

  return { width, height, center };
}

void spiridonov::Concave::move(point_t pos)
{
  double dx = pos.x - arrayOfPoints_[0].x;
  double dy = pos.y - arrayOfPoints_[0].y;

  for (int i = 0; i < 4; ++i)
  {
    arrayOfPoints_[i].x += dx;
    arrayOfPoints_[i].y += dy;
  }
}

void spiridonov::Concave::move(double x, double y)
{
  point_t newPos{ arrayOfPoints_[0].x + x, arrayOfPoints_[0].y + y };
  move(newPos);
}

void spiridonov::Concave::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Error: invalid coefficient to scale");
  }

  point_t center = getFrameRect().pos;

  for (int i = 0; i < 4; ++i)
  {
    double dx = arrayOfPoints_[i].x - center.x;
    double dy = arrayOfPoints_[i].y - center.y;

    arrayOfPoints_[i].x = center.x + dx * coefficient;
    arrayOfPoints_[i].y = center.y + dy * coefficient;
  }
  updateFrameRect();
}

void spiridonov::Concave::updateFrameRect()
{
  double minX = std::min({ arrayOfPoints_[0].x, arrayOfPoints_[1].x, arrayOfPoints_[2].x, arrayOfPoints_[3].x });
  double minY = std::min({ arrayOfPoints_[0].y, arrayOfPoints_[1].y, arrayOfPoints_[2].y, arrayOfPoints_[3].y });
  double maxX = std::max({ arrayOfPoints_[0].x, arrayOfPoints_[1].x, arrayOfPoints_[2].x, arrayOfPoints_[3].x });
  double maxY = std::max({ arrayOfPoints_[0].y, arrayOfPoints_[1].y, arrayOfPoints_[2].y, arrayOfPoints_[3].y });

  double width = maxX - minX;
  double height = maxY - minY;

  point_t center{ (minX + maxX) / 2, (minY + maxY) / 2 };

  frameRect_ = { width, height, center };
}

spiridonov::Concave* spiridonov::Concave::clone() const
{
  return new Concave(*this);
}


