#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "base-types.hpp"
namespace lopatina
{
  class Diamond: public Shape
  {
  public:
    Diamond(point_t central, point_t side_x, point_t side_y);
    virtual ~Diamond() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(point_t s);
    virtual void move(double x, double y);
    virtual void scale(double k);
  private:
    point_t central_vertex_;
    point_t side_x_vertex_;
    point_t side_y_vertex_;
  };
}

#endif
