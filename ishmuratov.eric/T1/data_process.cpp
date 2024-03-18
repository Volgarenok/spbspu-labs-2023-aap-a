#include "data_process.hpp"

double ishmuratov::triangleArea(const point_t & point1, const point_t & point2, const point_t & point3)
{
  return 0.5 * std::abs(point1.x * (point2.y - point3.y) + point2.x * (point3.y - point1.y) + point3.x * (point1.y - point2.y));
}

ishmuratov::point_t ishmuratov::triangleCenter(const point_t & point1, const point_t & point2, const point_t & point3)
{
  double center_x = (point1.x + point2.x + point3.x) / 3.0;
  double center_y = (point1.y + point2.y + point3.y) / 3.0;
  return { center_x, center_y };
}

ishmuratov::point_t ishmuratov::diamondCenter(const point_t & point1, const point_t & point2, const point_t & point3)
{
  point_t pointArray[3] = {point1, point2, point3};
  point_t pointx[2] = {point1, point2};
  size_t eq1 = 0;
  size_t eq2 = 0;
  for (size_t i = 0; i < 3; i++)
  {
    for (size_t j = 0; j < 3; j++)
    {
      if ((pointArray[i].x == pointArray[j].x) && (i != j))
      {
        pointx[0] = pointArray[i];
        pointx[1] = pointArray[j];
        eq1 = i;
        eq2 = j;
      }
    }
  }
  for (size_t k = 0; k < 3; k++)
  {
    if ((k != eq1) && (k != eq2) && (pointx[0].y == pointArray[k].y))
    {
      return pointx[0];
    }
    else if ((k != eq1) && (k != eq2) && (pointx[1].y == pointArray[k].y))
    {
      return pointx[1];
    }
  }
  return { 0, 0 };
}

double ishmuratov::pseudoScalar(const point_t & point1, const point_t & point2)
{
  return point1.x * point2.y - point1.y * point2.x;
}

void ishmuratov::scaleTriangle(point_t * pointArray, point_t center, double factor)
{
  point_t diffArray[3] = {};
  for (size_t i = 0; i < 3; ++i)
  {
    diffArray[i] = { (pointArray[i].x - center.x) * factor, (pointArray[i].y - center.y) * factor };
    pointArray[i] = { center.x + diffArray[i].x, center.y + diffArray[i].y };
  }
}

void ishmuratov::scaleShapes(Shape * shapes, point_t position, double factor)
{
  point_t initialPos = shapes->getFrameRect().pos;
  shapes->move(position);
  point_t newPos = shapes->getFrameRect().pos;
  shapes->scale(factor);
  shapes->move(factor * (initialPos.x - newPos.x), factor * (initialPos.y - newPos.y));
}
