#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace rebdev
{
  class Concave: public Shape
  {
    public:
      Concave();
      Concave(const point_t vertexs[]);
      Concave(const point_t firstVertex, const point_t secondVertex,
        const point_t thirdVertex, const point_t fourthVertex);

      double getArea() const;
      rectangle_t getFrameRect();
      void move(const point_t point);
      void move(const double x, const double y);
      void scale(const double k);
    private:
      point_t vertexs_[4];
  };
}
#endif
