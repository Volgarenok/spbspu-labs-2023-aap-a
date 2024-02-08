#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
#include <stdexcept>

namespace zakozhurnikova
{
  class Diamond : public Shape
  {
  public:
    Diamond() = delete;
    Diamond(const point_t& pointOne, const point_t& pointTwo, const point_t& pointThree) :
      pointOne_(point_t()),
      pointTwo_(point_t()),
      center_(point_t())
    {
      if (pointOne.getX() != pointTwo.getX() && pointOne.getY() != pointTwo.getY())
      {
        center_ = pointThree;
        pointOne_ = pointOne;
        pointTwo_ = pointTwo;
      } else if (pointOne.getX() != pointThree.getX() && pointOne.getY() != pointThree.getY()) {
        center_ = pointTwo;
        pointOne_ = pointOne;
        pointTwo_ = pointTwo;
      } else if (pointThree.getX() != pointTwo.getX() && pointThree.getY() != pointTwo.getY()) {
        center_ = pointOne;
        pointOne_ = pointTwo;
        pointTwo_ = pointThree;
      } else {
        throw std::invalid_argument("These points do not define a diamond");
      }

    }
    Diamond(const Diamond& di) :
      pointOne_(di.pointOne_),
      pointTwo_(di.pointTwo_),
      center_(di.center_)
    {}
    Diamond(Diamond&& sq) = default;
    ~Diamond()
    {}
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& p);
    void move(double dx, double dy);
    void scale(double k);
  private:
    point_t pointOne_;
    point_t pointTwo_;
    point_t center_;
  };
}
#endif