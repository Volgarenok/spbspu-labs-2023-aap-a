#ifndef RECTANGLE
#define RECTANGLE
#include "shape.hpp"

namespace petuhov
{
  class Rectangle : public Shape
  {
    public:
      Rectangle(const petuhov::point_t &pos, float width, float height);

      float getArea() const override;
      petuhov::rectangle_t getFrameRect() const override;
      void move(const petuhov::point_t & pos) override;
      void move(float dx, float dy) override;
      void scale(float factor) override;

    private:
      petuhov::rectangle_t rect_;
  };
}

#endif
