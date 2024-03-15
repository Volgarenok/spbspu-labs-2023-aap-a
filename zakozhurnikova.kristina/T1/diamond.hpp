#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"

namespace zakozhurnikova
{
  class Diamond: public Shape
  {
  public:
    Diamond() = delete;
    Diamond(const point_t& pointOne, const point_t& pointTwo, const point_t& pointThree);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& p);
    void move(double dx, double dy);
    void unsafeScale(double k);

  private:
    point_t pointOne_;
    point_t pointTwo_;
    point_t center_;
  };
  void initPoints(point_t* points, const point_t& pointOne, const point_t& pointTwo, const point_t& pointThree);
  bool isOnAxis(const point_t& center, const point_t& pointOne, const point_t& pointTwo);
}
#endif
