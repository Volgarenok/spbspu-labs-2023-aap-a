#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
  public:
    Rectangle(const point_t & pos, float width, float height);

    float getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & new_pos) override;
    void move(float dx, float dy) override;
    void scale(float factor) override;

  private:
    point_t pos_;
    float width_;
    float height_;
};

#endif
