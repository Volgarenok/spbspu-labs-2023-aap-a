#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include <cstddef>
namespace rebdev
{
  class Polygon: public Shape
  {
    public:
      Polygon();
      Polygon(point_t * const vertexs, size_t numOfVertexs);

      double getArea() const;
      rectangle_t getFrameRect();
      void move(const point_t point);
      void move(const double x, const double y);
      void scale(const double k);
    private:
      point_t * vertexs_;
      size_t numOfVertexs_;
  };
}
#endif
