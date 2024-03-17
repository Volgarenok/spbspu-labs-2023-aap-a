#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace nikitov
{
  class Diamond: public Shape
  {
  public:
    Diamond(const point_t& first, const point_t& second, const point_t& third);
    virtual ~Diamond() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& point);
    virtual void move(double dx, double dy);
    virtual Shape* clone() const;
  private:
    point_t first_;
    point_t second_;
    point_t third_;
    virtual void doScale(double ratio);
  };
}
#endif
