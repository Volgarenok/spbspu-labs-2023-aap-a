#include "polygon.hpp"
#include <stdexcept>
#include "figureFunction.hpp"

rebdev::Polygon::Polygon(const point_t * vertexes, size_t numOfVertexes):
  vertexes_(nullptr),
  numOfVertexes_(numOfVertexes)
{
  if (numOfVertexes < 3)
  {
    throw std::logic_error("polygon error");
  }
  for (size_t i = 0; i < (numOfVertexes - 1); ++i)
  {
    for (size_t j = (i + 1); j < numOfVertexes; ++j)
    {
      if ((vertexes[i].x == vertexes[j].x) && (vertexes[i].y == vertexes[j].y))
      {
        throw std::logic_error("polygon error");
      }
    }
  }

  vertexes_ = new point_t[numOfVertexes_];

  for (size_t i = 0; i < numOfVertexes_; ++i)
  {
    vertexes_[i] = vertexes[i];
  }
}

rebdev::Polygon::~Polygon()
{
  delete[] vertexes_;
}

double rebdev::Polygon::getArea() const
{
  return getFigureArea(vertexes_, numOfVertexes_);
}

rebdev::rectangle_t rebdev::Polygon::getFrameRect() const
{
  return getFrameRectangle(vertexes_, numOfVertexes_);
}

void rebdev::Polygon::move(const point_t & point)
{
  point_t center = getPolygonCenter();
  move(point.x - center.x, point.y - center.y);
}

void rebdev::Polygon::move(double x, double y)
{
  movePoints(x, y, vertexes_, numOfVertexes_);
}

void rebdev::Polygon::scale(double k)
{
  scaleFigure(vertexes_, numOfVertexes_, getPolygonCenter(), k);
}

rebdev::point_t rebdev::Polygon::getPolygonCenter()
{
  point_t center{0.0, 0.0};

  for (size_t i = 0; i < numOfVertexes_; ++i)
  {
    center.x += vertexes_[i].x;
    center.y += vertexes_[i].y;
  }

  center.x /= numOfVertexes_;
  center.y /= numOfVertexes_;

  return center;
}
