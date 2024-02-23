#include "geom_func.hpp"
#include <cmath>
#include <stdexcept>

void erohin::isoScale(Shape* shape, point_t pos, double ratio)
{
  point_t init_pos = shape->getFrameRect().pos;
  shape->move(pos);
  point_t new_pos = shape->getFrameRect().pos;
  shape->scale(ratio);
  shape->move(ratio * (init_pos.x - new_pos.x), ratio * (init_pos.y - new_pos.y));
}

void erohin::isoScale(CompositeShape& composite_shape, point_t pos, double ratio)
{
  for (size_t i = 0; i < composite_shape.size(); ++i)
  {
    isoScale(composite_shape[i], pos, ratio);
  }
}

double erohin::getDistance(point_t from, point_t to)
{
  double dx = from.x - to.x;
  double dy = from.y - to.y;
  return std::sqrt(dx * dx + dy * dy);
}

double* erohin::getSides(double* result, const point_t* point, size_t side_number)
{
  for (size_t i = 0; i < side_number; ++i)
  {
    result[i] = getDistance(point[i], point[(i + 1) % side_number]);
  }
  return result;
}

bool erohin::isPointOnSegment(point_t point, point_t begin, point_t end)
{
  return ((point.x - begin.x) * (point.x - end.x) < 0.0 && (point.y - begin.y) * (point.y - end.y) < 0.0);
}

erohin::point_t erohin::findIntersectionPoint(const point_t* point)
{
  double dx[3]{ 0.0 };
  double dy[3]{ 0.0 };
  for (int i = 0; i < 3; ++i)
  {
    dx[i] = point[i + 1].x - point[i].x;
    dy[i] = point[i + 1].y - point[i].y;
  }
  if (dy[0] * dx[2] == dy[2] * dx[0] || dx[0] == 0.0)
  {
    throw std::invalid_argument("Cannot find intersection");
  }
  point_t result = {0.0, 0.0};
  result.x = (point[2].y * dx[2] - point[2].x * dy[2]) * dx[0];
  result.x -= (point[0].y * dx[0] - point[0].x * dy[0]) * dx[0];
  result.x /= (dy[0] * dx[2] - dy[2] * dx[0]);
  result.y = point[0].y + (dy[0] / dx[0]) * (result.x - point[0].x);
  return result;
}

erohin::rectangle_t erohin::findPointsFrameRect(const point_t* point, size_t number)
{
  point_t left_lower = point[0];
  point_t right_upper = point[0];
  for (size_t i = 1; i < number; ++i)
  {
    left_lower.x = std::min(point[i].x, left_lower.x);
    left_lower.y = std::min(point[i].y, left_lower.y);
    right_upper.x = std::max(point[i].x, right_upper.x);
    right_upper.y = std::max(point[i].y, right_upper.y);
  }
  double width = right_upper.x - left_lower.x;
  double height = right_upper.y - left_lower.y;
  return { width, height, {left_lower.x + width / 2.0, left_lower.y + height / 2.0} };
}

erohin::rectangle_t erohin::findRectangleFrameRect(point_t left_lower_corner, point_t right_upper_corner)
{
  double width = right_upper_corner.x - left_lower_corner.x;
  double height = right_upper_corner.y - left_lower_corner.y;
  return { width, height, {left_lower_corner.x + width / 2.0, left_lower_corner.y + height / 2.0} };
}

erohin::rectangle_t erohin::findDiamondFrameRect(point_t corner1, point_t corner2, point_t corner3)
{
  rectangle_t result = { 0.0, 0.0, { 0.0, 0.0 } };
  point_t corner[3]{ corner1, corner2, corner3 };
  double side[3]{ 0.0 };
  getSides(side, corner, 3);
  int center_index = 0;
  for (int i = 0; i < 3; ++i)
  {
    if (side[i] >= side[(center_index + 1) % 3])
    {
      center_index = (i + 2) % 3;
    }
    if (corner[i].x == corner[(i + 1) % 3].x && corner[i].y != corner[(i + 1) % 3].y)
    {
      result.height = 2 * side[i];
    }
    if (corner[i].y == corner[(i + 1) % 3].y && corner[i].x != corner[(i + 1) % 3].x)
    {
      result.width = 2 * side[i];
    }
  }
  result.pos = corner[center_index];
  return result;
}
