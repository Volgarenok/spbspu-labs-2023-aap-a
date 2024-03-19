#include "addShape.hpp"

void chernov::addFigure(Shape** shapes, size_t& size, Shape* shape)
{
  Shape** newShapes = new Shape* [size + 1];
  for (size_t i = 0; i < size; ++i)
  {
    newShapes[i] = shapes[i];
  }
  newShapes[size] = shape;

  delete[] shapes;

  shapes = newShapes;

  size++;
}
