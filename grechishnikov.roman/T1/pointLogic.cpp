#include "pointLogic.hpp"
#include <algorithm>
#include <stdexcept>

grechishnikov::point_t grechishnikov::getAveragePoint(const point_t* points, size_t size)
{
  double average_x = 0;
  double average_y = 0;
  for (size_t i = 0; i < size; i++)
  {
    average_x += points[i].x;
    average_y += points[i].y;
  }
  average_x /= size;
  average_y /= size;
  return { average_x, average_y };
}

grechishnikov::rectangle_t grechishnikov::getFrameRectGeneral(const point_t* points, size_t size)
{
  double max_x = points[0].x;
  double max_y = points[0].y;
  double min_x = points[0].x;
  double min_y = points[0].y;

  for (size_t i = 1; i < size; i++)
  {
    max_x = std::max(max_x, points[i].x);
    max_y = std::max(max_y, points[i].y);
    min_x = std::min(min_x, points[i].x);
    min_y = std::min(min_y, points[i].y);
  }

  double width = max_x - min_x;
  double height = max_y - min_y;
  point_t pos = { min_x + width / 2, min_y + height / 2 };
  return { width, height, pos };
}


void grechishnikov::scalePoints(point_t* points, size_t size, size_t rate)
{
  if (rate <= 0)
  {
    throw std::logic_error("Incorrect scale ratio");
  }
  unsafeScalePoints(points, size, rate);
}

void grechishnikov::unsafeScalePoints(point_t* points, size_t size, size_t rate)
{
  point_t aPos = getAveragePoint(points, size);
  for (size_t i = 0; i < size; i++)
  {
    scalePoint(points[i], aPos, rate);
  }
}

void grechishnikov::scalePoint(point_t& point, const point_t& scalePoint, size_t rate)
{
  point.x = scalePoint.x + (point.x - scalePoint.x) * rate;
  point.y = scalePoint.y + (point.y - scalePoint.y) * rate;
}

void grechishnikov::movePoints(point_t* points, size_t size, double dx, double dy)
{
  for (size_t i = 0; i < size; i++)
  {
    points[i].x += dx;
    points[i].y += dy;
  }
}
