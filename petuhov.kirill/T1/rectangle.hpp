#ifndef RECTANGLE
#define RECTANGLE
#include "shape.hpp"

namespace petuhov
{
  class Rectangle : public Shape
  {
    public:
      Rectangle(const point_t & pos, double width, double height);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(const point_t & pos) override;
      void scale(double factor) override;
    private:
      rectangle_t rect_;
  };
}

#endif
