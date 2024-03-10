#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace petuhov
{
  class Circle: public petuhov::Shape
  {
    public:
      Circle(const petuhov::point_t &pos, float radius);

      float getArea() const override;
      petuhov::rectangle_t getFrameRect() const override;
      void move(const petuhov::point_t &pos) override;
      void move(float dx, float dy) override;
      void scale(float factor) override;
    private:
      petuhov::point_t center_;
      float radius_;
  };
}

#endif
