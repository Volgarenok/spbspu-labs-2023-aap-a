#include "concave.hpp"
#include <limits>

rebdev::Concave::Concave():
  vertexs_{
    rebdev::point_t{0.0, 0.0}, rebdev::point_t{0.0, 0.0}, rebdev::point_t{0.0, 0.0}, rebdev::point_t{0.0, 0.0}
  }
{};
rebdev::Concave::Concave(const point_t vertexs[]):
  vertexs_{
    vertexs[0], vertexs[1], vertexs[2], vertexs[3]
  }
{};
rebdev::Concave::Concave(const point_t firstVertex, const point_t secondVertex,
  const point_t thirdVertex, const point_t fourthVertex):
  vertexs_{
    firstVertex, secondVertex, thirdVertex, fourthVertex
  }
{};

double rebdev::Concave::getArea() const
{
  double sum = 0;
  for(int i = 0; i < 3; ++i)
  {
    sum += (vertexs_[i].x_ - vertexs_[i + 1].x_) * (vertexs_[i].y_ + vertexs_[i + 1].y_);
  }
  sum += (vertexs_[3].x_ - vertexs_[0].x_) * (vertexs_[3].y_ + vertexs_[0].y_);
  return  ((sum >= 0) ? sum : -sum);
};

rebdev::rectangle_t rebdev::Concave::getFrameRect()
{
  double xMin = std::numeric_limits< double >::min(), xMax = std::numeric_limits< double >::max();
  double yMin = xMin, yMax = xMax;
  for (int i = 0; i < 4; ++i)
  {
    xMin = ((xMin >= vertexs_[i].x_) ? vertexs_[i].x_ : xMin);
    yMin = ((yMin >= vertexs_[i].y_) ? vertexs_[i].y_ : yMin);
    xMax = ((xMax <= vertexs_[i].x_) ? vertexs_[i].x_ : xMax);
    yMax = ((yMax <= vertexs_[i].y_) ? vertexs_[i].y_ : yMax);
  }
  return rectangle_t{(xMax - xMin), (yMax - yMin), point_t{xMin + (xMax - xMin)/2, yMin + (yMax - yMin)/2}};
};

void rebdev::Concave::move(const point_t point)
{
  double yChange = vertexs_[3].y_ - point.y_;
  double xChange = vertexs_[3].x_ - point.x_;
  for (int i = 0; i < 4; ++i)
  {
    vertexs_[i].x_ += xChange;
    vertexs_[i].y_ += yChange;
  }
};

void rebdev::Concave::move(const double x, const double y)
{
  for (int i = 0; i < 4; ++i)
  {
    vertexs_[i].x_ += x;
    vertexs_[i].y_ += y;
  }
};

void rebdev::Concave::scale(const double k)
{
  for (int i = 0; i < 3; ++i)
  {
    vertexs_[i].x_ = (vertexs_[i].x_ - vertexs_[3].x_) * k + vertexs_[3].x_;
    vertexs_[i].y_ = (vertexs_[i].y_ - vertexs_[3].y_) * k + vertexs_[3].y_;
  }
};
