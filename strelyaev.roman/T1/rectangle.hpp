#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
class Rectangle: public Shape
{
  public:
   Rectangle(point_t, point_t);
   virtual double getArea() const;
   virtual rectangle_t getFrameRect();
   virtual void move(point_t);
   virtual void move(double);
   virtual void move(double, double);
   virtual void scale(double);
  private:
   point_t p1_;
   point_t p2_;
   point_t center_;
};
#endif