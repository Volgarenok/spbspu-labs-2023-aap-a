#ifndef RECTANGLE
#define RECTANGLE
#include "shape.hpp"

namespace petuhov
{
  class Rectangle : public Shape
  {
    public:
      Rectangle(const petuhov::point_t &pos, double width, double height);

      double getArea() const override;
      petuhov::rectangle_t getFrameRect() const override;
      void move(const petuhov::point_t & pos) override;
      void move(double dx, double dy) override;
      void scale(double factor) override;

    private:
      petuhov::rectangle_t rect_;
  };
}

#endif
