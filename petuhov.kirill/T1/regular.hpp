#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "shape.hpp"

namespace petuhov
{
  class Regular : public petuhov::Shape
  {
    public:
      Regular(const petuhov::point_t &pos, double radius, int vertexCount);

      double getArea() const override;
      petuhov::rectangle_t getFrameRect() const override;
      void move(const petuhov::point_t &pos) override;
      void move(double dx, double dy) override;
      void scale(double factor) override;

    private:
      petuhov::point_t center_;
      double radius_;
      int vertexCount_;
  };
}

#endif
