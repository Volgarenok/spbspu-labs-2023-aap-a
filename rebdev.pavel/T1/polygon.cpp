#include "polygon.hpp"
#include <cstddef>
#include <limits>

rebdev::Polygon::Polygon():
  vertexs_(nullptr),
  numOfVertexs_(0)
{};
rebdev::Polygon::Polygon(point_t * const vertexs, size_t numOfVertexs):
  vertexs_(new point_t[numOfVertexs]),
  numOfVertexs_(numOfVertexs)
{
  for (size_t i = 0; i < numOfVertexs; ++i)
  {
    vertexs_[i] = vertexs[i];
  }

};

double rebdev::Polygon::getArea() const
{
  double sum = 0;
  for(size_t i = 0; i < (numOfVertexs_ - 1); ++i)
  {
    sum += (vertexs_[i].x_ - vertexs_[i + 1].x_) * (vertexs_[i].y_ + vertexs_[i + 1].y_);
  }
  sum += (vertexs_[numOfVertexs_ - 1].x_ - vertexs_[0].x_) * (vertexs_[numOfVertexs_ - 1].y_ + vertexs_[0].y_);
  sum /= 2;
  return  ((sum >= 0) ? sum : -sum);
};

rebdev::rectangle_t rebdev::Polygon::getFrameRect()
{
  double xMin = std::numeric_limits< double >::min(), xMax = std::numeric_limits< double >::max();
  double yMin = xMin, yMax = xMax;
  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    xMin = ((xMin >= vertexs_[i].x_) ? vertexs_[i].x_ : xMin);
    yMin = ((yMin >= vertexs_[i].y_) ? vertexs_[i].y_ : yMin);
    xMax = ((xMax <= vertexs_[i].x_) ? vertexs_[i].x_ : xMax);
    yMax = ((yMax <= vertexs_[i].y_) ? vertexs_[i].y_ : yMax);
  }
  return rectangle_t{(xMax - xMin), (yMax - yMin), point_t{xMin + (xMax - xMin)/2, yMin + (yMax - yMin)/2}};
};

void rebdev::Polygon::move(const point_t point)
{
  point_t center{0.0, 0.0};

  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    center.x_ += vertexs_[i].x_;
    center.y_ += vertexs_[i].y_;
  }

  center.x_ /= numOfVertexs_;
  center.y_ /= numOfVertexs_;

  double xChange = center.x_ - point.x_;
  double yChange = center.y_ - point.y_;
  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    vertexs_[i].x_ += xChange;
    vertexs_[i].y_ += yChange;
  }
};

void rebdev::Polygon::move(const double x, const double y)
{
  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    vertexs_[i].x_ += x;
    vertexs_[i].y_ += y;
  }
};

void rebdev::Polygon::scale(const double k)
{
  point_t center{0.0, 0.0};

  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    center.x_ += vertexs_[i].x_;
    center.y_ += vertexs_[i].y_;
  }

  center.x_ /= numOfVertexs_;
  center.y_ /= numOfVertexs_;

  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    vertexs_[i].x_ = (vertexs_[i].x_ - center.x_) * k + center.x_;
    vertexs_[i].y_ = (vertexs_[i].y_ - center.y_) * k + center.y_;
  }

};
