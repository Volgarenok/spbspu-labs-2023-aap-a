#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"

namespace rebdev
{
  class Polygon: public Shape
  {
    public:
      Polygon(const point_t * vertexes, size_t numOfVertexes);

      virtual ~Polygon();
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(const point_t & point);
      virtual void move(double x, double y);
      virtual void scale(double k);
    private:
      point_t * vertexes_;
      size_t numOfVertexes_;

      point_t getPolygonCenter();
  };
}

#endif
