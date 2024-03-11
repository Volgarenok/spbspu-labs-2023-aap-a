#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "shape.hpp"

namespace petuhov
{
  class Regular : public petuhov::Shape
  {
    public:
      Regular(const petuhov::point_t &pos, float radius, int vertexCount);

      float getArea() const override;
      petuhov::rectangle_t getFrameRect() const override;
      void move(const petuhov::point_t &pos) override;
      void move(float dx, float dy) override;
      void scale(float factor) override;

    private:
      petuhov::point_t center_;
      float radius_;
      int vertexCount_;
  };
}

#endif
