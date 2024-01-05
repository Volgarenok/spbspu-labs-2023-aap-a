#ifndef COMLEXQUAD_HPP
#define COMLEXQUAD_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace erohin
{
  class Complexquad : public Shape
  {
  public:
    Complexquad();
    Complexquad(point_t* corner);
    virtual ~Complexquad();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(double dx, double dy);
    virtual void move(point_t point);
    virtual void scale(double ratio);
  private:
    point_t* vertex_;
    point_t center_;
  };
}

#endif
