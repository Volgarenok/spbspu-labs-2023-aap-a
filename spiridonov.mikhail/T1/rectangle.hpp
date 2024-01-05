#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

namespace spiridonov
{
  class Rectangle : public Shape
  {
    public:
      Rectangle() : frameRect_{ 0.0, 0.0, {0.0, 0.0} }
      {}
      Rectangle(double width, double height, double x, double y) :
        frameRect_{ width, height, {x, y} }
      {}
      double getArea();
      rectangle_t getFrameRect();
      void move(point_t pos) override;
      void move(double x, double y) override;
      void scale(double coefficient) override;
      Shape* clone() const override
      {
        return new Rectangle(*this);
      }
      ~Rectangle() = default;
      private:
        rectangle_t frameRect_;
    };
}

#endif
