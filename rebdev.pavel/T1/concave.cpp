#include "concave.hpp"
#include <cstddef>
#include <stdexcept>
#include "figureFunction.hpp"

rebdev::Concave::Concave(const point_t & a, const point_t & b, const point_t & c, const point_t & d):
  vertexes_{a, b, c, d}
{
  bool isConcave = false;

  for (size_t i = 0; ((i < 4) && (!isConcave)); ++i)
  {
    if (!isTriangle(vertexes_[i], vertexes_[(i + 1) % 4], vertexes_[(i + 2) % 4]))
    {
      continue;
    }

    double arr[3] = {0.0, 0.0, 0.0};
    for (size_t j = 0; j < 3; ++j)
    {
      point_t vertexesArr[3] = {vertexes_[(i + j) % 4], vertexes_[(i + 3) % 4], vertexes_[(i + (j + 1) % 3) % 4]};

      arr[j] = (vertexesArr[0].x - vertexesArr[1].x) * (vertexesArr[2].y - vertexesArr[0].y);
      arr[j] -= (vertexesArr[2].x - vertexesArr[0].x) * (vertexesArr[0].y - vertexesArr[1].y);
    }

    bool identicalSigns = ((arr[0] > 0) && (arr[1] > 0) && (arr[2] > 0));
    identicalSigns = (identicalSigns || ((arr[0] < 0) && (arr[1] < 0) && (arr[2] < 0)));

    if (identicalSigns)
    {
      point_t vertexes[4] = {vertexes_[0], vertexes_[1], vertexes_[2], vertexes_[3]};
      vertexes_[0] = vertexes[i];
      vertexes_[1] = vertexes[(i + 1) % 4];
      vertexes_[2] = vertexes[(i + 3) % 4];
      vertexes_[3] = vertexes[(i + 2) % 4];
      isConcave = true;
    }
  }
  if (!isConcave)
  {
    throw std::logic_error("concave error");
  }
}

double rebdev::Concave::getArea() const
{
  return getFigureArea(vertexes_, 4);
}

rebdev::rectangle_t rebdev::Concave::getFrameRect() const
{
  return getFrameRectangle(vertexes_, 4);
}

void rebdev::Concave::move(const point_t & point)
{
  move(point.x - vertexes_[2].x, point.y - vertexes_[2].y);
}

void rebdev::Concave::move(double x, double y)
{
  movePoints(x, y, vertexes_, 4);
}

void rebdev::Concave::scale(double k)
{
  scaleFigure(vertexes_, 4, vertexes_[2], k);
}

bool rebdev::isTriangle(const point_t & f, const point_t & s, const point_t & t)
{
  return (((t.x - f.x) / (s.x - f.x)) != ((t.y - f.y) / (s.y - f.y)));
}
