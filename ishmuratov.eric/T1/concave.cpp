#include "concave.hpp"
#include "data_process.hpp"

ishmuratov::Concave::Concave(const point_t & point1, const point_t & point2, const point_t & point3, const point_t & point4):
  tri1_(Triangle(point1, point2, point3)),
  tri2_(Triangle(point2, point3, point4))
{
  if (tri1_.getArea() == 0)
  {
    throw std::invalid_argument("First 3 points don't form triangle!");
  }
  ishmuratov::point_t v14 = { point1.x - point4.x, point1.y - point4.y };
  ishmuratov::point_t v21 = { point2.x - point1.x, point2.y - point1.y };
  ishmuratov::point_t v24 = { point2.x - point4.x, point2.y - point4.y };
  ishmuratov::point_t v32 = { point3.x - point2.x, point3.y - point2.y };
  ishmuratov::point_t v34 = { point3.x - point4.x, point3.y - point4.y };
  ishmuratov::point_t v13 = { point1.x - point3.x, point1.y - point3.y };
  double ps1 = ishmuratov::pseudoScalar(v14, v21);
  double ps2 = ishmuratov::pseudoScalar(v24, v32);
  double ps3 = ishmuratov::pseudoScalar(v34, v13);
  if (!(ps1 < 0 && ps2 < 0 && ps3 < 0) && !(ps1 > 0 && ps2 > 0 && ps3 > 0))
  {
    throw std::invalid_argument("Last point is outside of the triangle!");
  }
}

ishmuratov::Concave::~Concave() = default;

double ishmuratov::Concave::getArea() const
{
  return tri1_.getArea() - tri2_.getArea();
}

ishmuratov::rectangle_t ishmuratov::Concave::getFrameRect() const
{
  return tri1_.getFrameRect();
}

void ishmuratov::Concave::move(point_t position)
{
  tri1_.move(position);
  tri2_.move(position);
}

void ishmuratov::Concave::move(double dx, double dy)
{
  tri1_.move(dx, dy);
  tri2_.move(dx, dy);
}

void ishmuratov::Concave::scale(double factor)
{
  if (factor <= 0 )
  {
    throw std::runtime_error("Invalid factor!");
  }
  tri1_.scale(factor);
  tri2_.scale(factor);
}
