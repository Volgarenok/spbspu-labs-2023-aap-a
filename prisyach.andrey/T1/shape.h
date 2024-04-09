#ifndef SHAPE_H
#define SHAPE_H
#include "base_types.h"

class Shape // описание абстрактного класса
{
public:
  virtual double getArea() const = 0; // вычисление площади
  virtual rectangle_t getFrameRect() const = 0; // получение ограничивающего прямоугольника для фигуры
  virtual void move(double dx, double dy) = 0; // перемещение центра фигуры в виде смещений по осям абсцисс и ординат
  virtual void move(point_t position) = 0; // перемещение центра фигуры в конкретную точку
  void checkScale(double k); // проверить коэффициент k >0 
  virtual void scale(double k) noexcept = 0; // масштабирование фигуры относительно её центра с указанным коэффициентом
  virtual ~Shape() = default;
  virtual Shape* clone() const = 0; // дублировать фигуру
};

#endif
